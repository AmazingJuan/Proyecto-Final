#include "reglas_juego.h"
#include "utilities.h"

reglas_juego::reglas_juego(QVector<QGraphicsView *> &graphics, QVector<QPushButton *> &shop_buttons, partida *partida)
{

    //SE INICIALIZAN LAS VARIABLES DE ESTADO DEL JUEGO.
    ship = nullptr;
    next_scene = -1;
    in_scene_obstacles = 0;
    current_stage = 1;
    current_scene = -1;
    twister_death = false;

    //SE DEFINEN LOS BOTONES, LOS GRAPHICS VIEW Y LAS PARTIDAS.
    this -> shop_buttons = shop_buttons;
    interfaces = graphics;
    saves = partida;

    //SE ALOJA MEMORIA PARA LOS TIMER.
    change_scene_timer = new QTimer;
    wave_timer = new QTimer;
    game_timer = new QTimer;
    dispatch_obstacles_timer = new QTimer;

    //SE ESTABLECEN LOS PRECIOS DE LOS LEVEL UP DEL BARCO.
    shop_prices[0] = 100;
    shop_prices[1] = 200;
    shop_prices[2] = 400;

    initial_conections(); //Se realizan las conexiones iniciales.

    //Se añaden los mensajes de pantalla de carga al vector de mensajes.
    stage_messages.push_back(stage_1);
    stage_messages.push_back(stage_2);
    stage_messages.push_back(stage_3);

    //SE INICIALIZAN LOS OBJETOS NECESARIOS PARA LA REPRODUCCIÓN DE AUDIO.
    reproductor = new QMediaPlayer;
    output = new QAudioOutput;
    reproductor -> setAudioOutput(output);
}

void reglas_juego::main_menu(){
    emit show_screen(main_menu_scene); //Se muestra el menu principal.
    current_scene = 0; //Se establece la escena actual como 0.
    show_image(scenes[current_scene], QString(":/imagenes/Imagenes/menuppal.png"), image_labels); //Se muestra la imagen del menu principal.
    play_music("qrc:/audio/Audios/intro.mp3", reproductor, output, false); //Se reproduce la musica de introducción.
}

void reglas_juego::main_menu_load()
{
    emit show_screen(main_menu_load_scene);  //Se muestra el menu principal de carga.
    current_scene = 1; //Se establece la escena actual como 1.
    show_image(scenes[current_scene], QString(":/imagenes/Imagenes/menuppal_carga.png"), image_labels); //Se muestra la imagen del menu principal de carga.
    play_music("qrc:/audio/Audios/intro.mp3", reproductor, output, false); //Se reproduce la musica de introducción.
}

reglas_juego::~reglas_juego()
{
    stop_game(); //Detiene la ejecución del juego (timers, eventos, etcetera).
    delete change_scene_timer; //Se libera memoria de el temporizador de cambio de escena.
    delete ship; //Se libera la memoria ocupada por el barco.

    //Se libera memoria de los encargados de reproducir audio.
    delete reproductor;
    delete output;

    //SE EJECUTAN FUNCIONES QUE LIBERAN MEMORIA DE LOS VECTORES.
    dispose_obstacles();
    dispose_shop_obstacles();
    dispose_image_labels();
    dispose_scenes();
}

void reglas_juego::setup()
{
    //Se inicializan las escenas que se usarán en el juego, y se les establece el tamaño.
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    scenes.push_back(new QGraphicsScene);
    scenes[scenes.size()-1]->setSceneRect(0, 0, 700, 700);
    int indice = 0;
    for(auto it = scenes.begin(); it != scenes.end(); it++) {
        interfaces[indice]->setScene(scenes[indice]); //Se asocia cada escena a un graphics view.
        indice++;
    }
    scenes[2] -> setBackgroundBrush(Qt::black); //A la escena del mensaje para el usuario se le establece un fondo blanco.
    saves->exists_file(); //Llama a la funcion que verifica si hay una partida guardada o no.
}

void reglas_juego::key_pressed(int key)
{
    if(current_scene == 3){
        if(key == Qt::Key_W){
            ship -> move(0); //Cambia la animación del barco.
            emit change_speed(1); //Emite una señal que simula el impulso del barco en direccion del movimiento del mismo.
        }
        else if(key == Qt::Key_A){
            ship -> move(1); //Cambia la animación del barco y lo mueve hacia la izquierda.
        }
        else if(key == Qt::Key_D){
            ship -> move(2); //Cambia la animación del barco y lo mueve hacia la derecha.
        }
        else if(key == Qt::Key_S){
            emit change_speed(-1); //Emite una señal que simula el impulso del barco en direccion contraria al movimiento del mismo.
        }
        else if(key == Qt::Key_Escape){
            handle_menu_compra(); //Abre el menu de compra
        }
    }
    else if(current_scene == 4 && key == Qt::Key_Escape) handle_menu_compra(); //Cierra el menu de compra.
}

void reglas_juego::obstacle_connections(obstaculo *obstacle)
{
    //Realaiza las conexiones necesarias para cada obstaculo que se genere.
    connect(obstacle, &obstaculo::ask_move, this, &reglas_juego::try_move);
    connect(this, &reglas_juego::crash, obstacle, &obstaculo::start_crash);
    connect(this, &reglas_juego::change_speed, obstacle, &obstaculo::change_speed);
    connect(obstacle, &obstaculo::surpassed_limit, this, &reglas_juego::outside_removal);
}

void reglas_juego::start_game()
{
    saves -> save_load(); //Carga las partidas guardadas (si el usuario selecciono iniciar, se carga una partida con los datos por defecto).
    if(!saves -> getError()){ //Si no hubo error al cargar la partida se ejecuta este bloque.
        QVector<int> data = saves -> getData(); //Se obtienen los datos.
        unsigned short level = data[0], coins = data[1], stage = data[2], hp = data[3], time = data[4]; //Se crean variables que identifiquen al os datos.
        //Se inicializa el juego con los datos obtenidos.
        current_stage = stage;
        game_time_counter = time;
        ship = new barco(level, hp, 300 , 400);
        ship -> setMoney(coins);
        scenes[3] -> addItem(ship); //Se añade a la stage el barco.
        setup_shop(); //Se establecen los barcos que se encuentran en el menu de compra.
        show_middle_message(stage_messages[current_stage - 1]); //Se muestra el mensaje correspondiente a la stage actual.
        next_scene = 3;
    }
}

void reglas_juego::change_scene()
{
    switch_scenes(); //Cambia las escenas.
    current_scene = next_scene; //Establece la escena actual como la que fue la siguiente anteriormente.
    change_scene_timer -> stop(); //Detiene el contador de cambio de escena.
    if(current_scene == 3 && !twister_death){
        if(current_stage >= 2) wave_timer -> start(30000); //Se inicia el contador de oleaje.
        setup_stage(); //Se configura la stage actual.
        game_timer->start(1000); //Se inicializa el temporizador del juego.
        play_music("qrc:/audio/Audios/stage_" +  QString::number(current_stage) + ".mp3", reproductor, output, false); //Se emite la musica correspondiente al a stage actual.
    }
    else if(current_scene == 3 && twister_death){
        show_image(scenes[3], ":/imagenes/Imagenes/twister.png", image_labels); //Se pone una imagen de un tornado

        //Se coloca al barco en el centro de la escena.
        ship -> setX(350);
        ship -> setY(150);

        play_music("qrc:/audio/Audios/twister.ogg", reproductor, output, false); //Se reproduce la musica correspondiente del tornado.
        emit mcu(); //Emite una señal que inicia el movimiento circular del barco.
    }
}

void reglas_juego::timer_changed()
{
    game_time_counter--; //Disminuye en uno el contador de segundos del juego.
    emit shoot_label_change(6, "TIEMPO RESTANTE: " + QString::number(game_time_counter), false); //Actualiza el label que contiene los segundos.
    if(game_time_counter == 0){
        handle_end_stage(); //Si el contador llega a cero se ejecuta la funcion encargada de administrar la finalización de una stage.
    }
}

void reglas_juego::handle_mcu_finish()
{
    gameover(); //Si el movimiento circular termino es porque la espiral del tornado acabó, por lo tanto el juego se acaba inmediatamente.
}

void reglas_juego::loadMenu(bool dato)
{
    if(dato) main_menu_load(); //Ejecuta el menu principal o de carga dependiendo del booleano que se ingrese.
    else main_menu();

}

void reglas_juego::try_move(QPoint pos, QGraphicsProxyWidget *widget, bool crash_happening)
{
    obstaculo *cast = dynamic_cast<obstaculo *>(widget); //Castea el widget como un obstaculo.
    bool aux = is_colliding(widget); //Verifica si el widget colisiona con el barco.
    if(pos.x() <= 600 && pos.x() >= 0){ //Verifica que el rango de movimiento esté en la escena.
        if(!crash_happening){ //El bloque se ejecuta si no hay un choque sucediendo.
            if(!aux){
                //Si no hay colision se mueve el widget a la posicion deseada.
                widget->setX(pos.x());
                widget->setY(pos.y());
            }
            else{
                if(cast -> getIs_dangerous()){ //Si es un widget peligroso se ejecuta este bloque.
                    if(cast ->getIs_twister()){ //Si el widget es un tornado se ejecuta este bloque.
                        stop_game(); //Se detiene la ejecución del juego.

                        //Se le pone texto vacio a los labels de vida y tiempo restante.
                        emit shoot_label_change(5, "", false);
                        emit shoot_label_change(6, "", false);

                        twister_death = true; //Habilita la variable de control que indica que hubo muerte por tornado.

                        show_middle_message("Vaya...\nHas caido en un\nTORNADO."); //Muestra un mensaje que le indica al usuario que cayo en un tornado.
                    }
                    else if(ship -> getHp() - cast -> getIssued_damage() > 0){ //Si no es un tornado, entonces es un obstaculo peligroso. Verifica si el daño que hace el obstaculo no destruye el barco.
                        emit crash(widget); //Emite la señal para que el obstaculo haga la animacion de crash.
                        emit crash_ship(cast -> getSpeed()); //Emite la señal para que el barco haga la animacion de crash.
                        ship -> setHp(ship -> getHp() - cast -> getIssued_damage()); //Le disminuye la vida al barco.
                        emit shoot_label_change(5, QString("HP:" + QString::number(ship -> getHp())) + "/" + QString::number(ship -> getLevel() * 50), false); //Actualiza el label de vida del barco.
                        saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter); //Guarda los datos del barco.
                        cast -> play_own_music(); //Se reproduce el sonido de choque.
                    }
                    else{
                        gameover(); //Como el barco no puede soportar el golpe del obstaculo, el juego se acaba.
                    }
                }
                else{ //Como no es peligroso, entonces es una moneda.
                    cast -> play_own_music(); //Se emite el sonido de recolectar moneda.
                    outside_removal(cast); //Se remueve el objeto de la escena.
                    ship -> addMoney(random_short(min_money_per_coin, max_money_per_coin)); //Le da al usuario dinero aleatorio.
                    saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter); //Guarda los datos actuales.
                }
            }
        }
        else{ //Si está en la animación de choque permite al widget moverse libremente.
            widget->setX(pos.x());
            widget->setY(pos.y());
        }
    }
}

void reglas_juego::dispatch_obstacles()
{
    if(in_scene_obstacles < (current_stage + 1)){ //Verifica que los obstaculos en la escena sean inferiores al numero de la stage + 1.
        unsigned short columna = random_short(0, 6); //Se establece en que columna spawneará el obstaculo.

        //Condicionales para spawnear una moneda, un barco enemigo o un tornado.
        if(random_bool()) moving_obstacles.push_back(new obstaculo(4, ship -> getMass(), ship -> getShip_force(), 100, ship -> getMax_speed()));
        else if(current_stage == 3 && random_short(0,10) >= 7) moving_obstacles.push_back(new obstaculo(4, ship -> getMass(), ship -> getShip_force(), 100, ship -> getMax_speed()));
        else moving_obstacles.push_back(new obstaculo(random_short(1,current_stage), ship -> getMass(), ship -> getShip_force(), 100, ship -> getMax_speed()));


        scenes[3] -> addItem(moving_obstacles[moving_obstacles.size() - 1]); //Añade a la escena el obstaculo generado
        moving_obstacles[moving_obstacles.size() - 1] -> setX(columna * 100); //Pone al obstaculo en la columna deseada
        moving_obstacles[moving_obstacles.size() - 1] -> setY(-100); //Pone al barco 100 pixeles fuera de la escana.
        obstacle_connections(moving_obstacles[moving_obstacles.size() - 1]); //Realiza las conexiones necesarias para el nuevo obstaculo.
        moving_obstacles[moving_obstacles.size() - 1]->start_movement(); //Inicia el movimiento usual del obstaculo.
        in_scene_obstacles++; //Actualiza el contador de obstaculos en la escena.
    }
}

void reglas_juego::wave_event()
{
    emit shm(); //Ordena al barco iniciar el movimiento armonico.
    shop_obstacles[2] -> play_own_music(); //Se emite una musica de oleaje.
    wave_timer -> stop();
}

void reglas_juego::handle_end_stage()
{
    current_stage++; //Se actualiza el contador de stage.
    if(current_stage != 4){ //Verifica que no sea la ultima stage.
        game_timer -> stop(); //Se detiene el temporizador que cuenta los segundos del juego.
        if(wave_timer -> isActive()) wave_timer -> stop(); //Si esta sucediendo un MAS, se detiene inmediatamente.
        dispatch_obstacles_timer->stop(); //Se detiene la generacion de obstaculos.
        ship -> stop_movement(); //Se detiene el movimiento del barco.
        dispose_obstacles(); //Se borran los obstaculos en la escena, y los que fueron removidos.
        in_scene_obstacles = 0; //Se inicializa de nuevo el contador de obstaculos en la escena.
        show_middle_message(stage_messages[current_stage - 1]); //Muestra el mensaje de la stage siguiente.
        next_scene = 3;
    }
    else{
        win(); //Si  nos encontramos en la stage 4, es decir, ya se paso la stage 3, entonces se ejecuta la funcion de victoria.
    }
}

void reglas_juego::gameover()
{
    stop_game(); //Se detiene la ejecucion del juego.
    play_music("qrc:/audio/Audios/gameover.ogg", reproductor, output, false); //Se reproduce musica de juego terminado.
    if(scenes[3]->items().contains(ship))scenes[3] -> removeItem(ship); //Se remueve el barco de la escena, en el caso de que esté.
    next_scene = 2;
    switch_scenes(); //Cambia la escena a la interfaz de mensaje.
    emit shoot_button_change(0); //Hace visible el boton de salida.
    show_image(scenes[2], ":/imagenes/Imagenes/gameover.png", image_labels); //Muestra la imagen de gameover.
    emit shoot_label_change(0, "", false); //Quita el mensaje de la anterior stage.
}

void reglas_juego::win()
{
    stop_game(); //Se detiene la ejecucion del juego.
    play_music("qrc:/audio/Audios/victory.mp3", reproductor, output, false); //Se reproduce musica de victoria.
    if(scenes[3]->items().contains(ship))scenes[3] -> removeItem(ship); //Se remueve el barco de la escena, en el caso de que esté.
    next_scene = 2;
    switch_scenes(); //Cambia la escena a la interfaz de mensaje.
    emit shoot_button_change(0); //Hace visible el boton de salida.
    show_image(scenes[2], ":/imagenes/Imagenes/win.png", image_labels); //Muestra la imagen de gameover.
    emit shoot_label_change(0, "", false); //Quita el mensaje de la anterior stage.
}

void reglas_juego::stop_game()
{
    dispose_obstacles(); //Borra los obstaculos removidos y los que están en escena.
    game_timer -> stop(); //Detiene el temporizador que cuenta los segundos de juego.
    change_scene_timer -> stop(); //Detiene el temporizador de cambio de escena.
    wave_timer -> stop(); //Detiene el timer de MAS.
    dispatch_obstacles_timer -> stop(); //Detiene el temporizador de la generación de enemigos.
    if(ship != nullptr) ship -> stop_movement(); //Detiene el movimiento del barco, en el caso de que esté inicializado el mismo.
}


void reglas_juego::manage_shop_buttons()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender()); //Se obtiene el botón presionado.
    unsigned short index = shop_buttons.indexOf(button); //Se obtiene el indice del boton en el vector de botones del menu de compra.
    if(ship -> getMoney() >= shop_prices[index] && index + 2 > ship -> getLevel()){ //Verifica que el usuario tenga dinero para comprar el barco y que no vaya a comprar una mejora inferior.
        ship -> setMoney(ship -> getMoney() - shop_prices[index]); //Disminuye el dinero del usuario.
        handle_menu_compra(); //Cierra el menu de compra.
        ship -> level_up(index + 2); //Ejecuta el level up al nivel que compró.
        update_shop(index + 1); //Se actualiza la tienda.
        saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter); //Se guardan los datos del usuario.
        shop_obstacles[0] -> play_own_music(); //Se reproduce la musica de 'kashing'.
        emit shoot_label_change(5, QString("HP:" + QString::number(ship -> getHp())) + "/" + QString::number(ship -> getLevel() * 50), false); //Se actualiza la nueva vida del barco.
    }
    else{
        shop_obstacles[1] -> play_own_music(); //Emite un sonido de accion fallida.
    }
}

void reglas_juego::show_middle_message(QString text)
{
    change_scene_timer -> start(15000); //Empieza a contar el temporizador de cambio de escena.
    next_scene = 2; //Establece como proxima escena la escena de mensaje.
    switch_scenes(); //Se cambia la escena.
    next_scene = 3; //Se pone como siguiente escena la escena de stage.
    emit shoot_label_change(0, text, true); //Se coloca el mensaje que la pantalla de carga.
    if(!twister_death) play_music("qrc:/audio/Audios/middle.wav", reproductor, output, false); //Si no hay muerte por tornado, entonces se reproduce la musica de la pantalla de carga.
    else play_music("qrc:/audio/Audios/twister_middle.mp3", reproductor, output, false); //Se reproduce la musica de la pantalla de carga para el tornado.
}

void reglas_juego::handle_menu_compra()
{
    update_shop(ship -> getLevel() - 1); //Se actualiza la tienda.
    if(current_scene == 3) next_scene = 4; //Si el usuario estaba en la escena de stages, entonces la siguiente escena será la de el menu de compra.
    else next_scene = 3; //De lo contrario, el usuario está en la escena de menu de compra, por lo cual la siguiente escena será la de stages.
    switch_scenes(); //Se cambia la escena.
}

void reglas_juego::update_shop(unsigned short blocked)
{
    int price = 0; //Se inicializa el contador de precio nulo.
    unsigned short cont = 0;
    for(; cont < 3; cont++){
        if(cont + 1 <= blocked){ //Verifica que el contador se menor o igual que los botones bloqueados.
            emit shoot_label_change(cont + 1, "", true); //Bora el label que indica el precio del barco actual.
            price += shop_prices[cont]; //Suma al contador de precio, el precio del barco actual.
            shop_prices[cont] = 0; //Settea como 0 el precio del barco actual.
        }
        else{ //Este else se ejecuta para las mejoras que no estén bloqueadas (si hay).
            QString aux = QString::number(shop_prices[cont] - price); //String con el precio nuevo del barco.
            shop_prices[cont] = shop_prices[cont] - price; //Actualiza el precio en el vector de precios.
            emit shoot_label_change(cont + 1, aux, true); //Edita el label para que se visualice en pantalla.
        }
    }
    emit shoot_label_change(cont + 1, QString(QString::number(ship -> getMoney()) + " COINS" ), false); //Actualiza el label de monedas.
}

void reglas_juego::initial_conections()
{
    //Realiza las conexiones iniciales para cuando se instancia el objeto.
    connect(saves, &partida::exists_save, this, &reglas_juego::loadMenu);
    connect(change_scene_timer, &QTimer::timeout, this, &reglas_juego::change_scene);
    connect(dispatch_obstacles_timer, &QTimer::timeout, this, &reglas_juego::dispatch_obstacles);
    connect(wave_timer, &QTimer::timeout, this, &reglas_juego::wave_event);
    connect(game_timer, &QTimer::timeout, this, &::reglas_juego::timer_changed);
}

void reglas_juego::stage_connections()
{
    //Hace las conexiones iniciales para cuando se crea va a iniciar stage.
    connect(ship, &barco::ask_move, this, &reglas_juego::try_move);
    connect(ship, &barco::mcu_finished, this, &reglas_juego::handle_mcu_finish);
    connect(this, &reglas_juego::shm, ship, &barco::start_shm);
    connect(this, &reglas_juego::crash_ship, ship, &barco::start_crash);
    connect(this, &reglas_juego::mcu, ship, &barco::start_mcu);
}

bool reglas_juego::is_colliding(QGraphicsProxyWidget *widget)
{
    if(widget != ship){ //Verifica que el widget que se ingresa no sea el barco.
        //Se establecen puntos en la mitad del label que contiene la QMovie del obstaculo y el barco, después se verifica que la distancia entre ellos sea menor a 60 pixeles.
        QPointF pos_ship = ship->pos();
        QPointF pos_widget = widget->pos();
        pos_ship.setX(pos_ship.x() + 50);
        pos_ship.setY(pos_ship.y() + 50);
        pos_widget.setX(pos_widget.x() + 50);
        pos_widget.setY(pos_widget.y() + 50);
        return calculate_distance(pos_ship, pos_widget) < 60; //retorna si la distancia entre los puntos es menor a 60 pixeles.
    }
    else{ //Se ejecuta este else, ya que el barco no puede colisionar consigo mismo.
        return false;
    }
}

void reglas_juego::dispose_obstacles()
{
    for(int cont = moving_obstacles.size() - 1; cont >= 0; cont--){ //Remueve los obstaculos en movimiento de la escena.
        moving_obstacles[cont] -> stop_movement();
        scenes[3]-> removeItem(moving_obstacles[cont]);
        removed_obstacles.push_back(moving_obstacles[cont]); //Los incluye en el vector de obstaculos removidos.
        moving_obstacles.removeOne(moving_obstacles[cont]);
    }
    dispose_removed_obstacles(); //Se libera la memoria de los obstaculos removidos.
}

void reglas_juego::dispose_removed_obstacles()
{
    //Se libera la memoria de los obstaculos removidos.
    for(int cont = 0; cont < removed_obstacles.size(); cont++){
        delete removed_obstacles[cont];
        removed_obstacles.remove(cont);
    }
}

void reglas_juego::dispose_shop_obstacles()
{
    //Elimina todos los obstaculos que se encuentran en el menu de compra.
    for(int cont = 0; cont < shop_obstacles.size(); cont++){
        delete shop_obstacles[cont];
    }
    shop_obstacles.clear();
}

void reglas_juego::dispose_scenes()
{
    //Libera la memoria de todas las escenas que están en el vector de escenas.
    for(unsigned short cont = 0; cont < scenes.size(); cont++) {
        delete scenes[cont];
    }
}

void reglas_juego::dispose_image_labels()
{
    //Elimina todos los labels de imagenes.
    for(unsigned short cont = 0; cont < image_labels.size(); cont++) {
        delete image_labels[cont];
    }
}

void reglas_juego::outside_removal(obstaculo *obs)
{
    //Remueve un obstaculo en movimiento de la escena.
    in_scene_obstacles--; //Se disminuye en uno los obstaculos activos en la escena.
    scenes[3] -> removeItem(obs); //Se remueve de la escena.
    moving_obstacles.removeOne(obs); //Se remueve del vector de obstaculos en movimiento.
    removed_obstacles.push_back(obs); //Se agrega al vector de obstaculos removidos.
    obs -> stop_movement(); //Se para el movimiento del obstaculo removido.
}

void reglas_juego::setup_stage()
{
    if(game_time_counter == 0) game_time_counter = game_duration; //Obecede a la duración del juego establecida por la macro 'game_duration'.

    //Ubica el barco en el centro de la escena.
    ship -> setX(300);
    ship -> setY(400);

    show_image(scenes[3], ":/imagenes/Imagenes/fondo_" + QString::number(current_stage) + ".jpg", image_labels); //Muestra la imagen de la stage actual.
    update_shop(ship -> getLevel() - 1);  //Actualiza la tienda.
    dispatch_obstacles_timer -> start(4000); //Ordena a los enemigos aparecer cada 4 segundos.
    stage_connections(); //Realiza las conexiones necesarias para la iniciar la stage.
    emit shoot_label_change(5, QString("HP:" + QString::number(ship -> getHp())) + "/" + QString::number(ship -> getLevel() * 50), false); //Muestra la vida actual del barco.
    emit shoot_label_change(6, "TIEMPO RESTANTE: " + QString::number(game_time_counter), false); //Muestra el tiempo restante.
    saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter); //Guarda los datos del juego.
}

void reglas_juego::setup_shop()
{
    show_image(scenes[4], ":/imagenes/Imagenes/menucompra.png", image_labels); //Establece la imagen del menu de compra en la escena 5.
    unsigned int var = 0;
    for(unsigned short cont = 0; cont < 3; cont++) {
        shop_obstacles.push_back(new obstaculo(6 + cont, 0, 0, 130, ship -> getMax_speed())); //Inicializa un obstaculo que estará en el menu de compra.

        //LOGICA PARA UBICAR EL OBSTACULO EN LA ESCENA 5.
        shop_obstacles[cont] -> setX(390);
        if(cont == 0) var = 70;
        else if(cont == 1) var = 241;
        else var = 413;
        shop_obstacles[cont] -> setY(var);

        scenes[4] -> addItem(shop_obstacles[cont]); //Añade el obstaculo a la escena.
    }
}

void reglas_juego::switch_scenes()
{
    emit hide_screen(current_scene); //Oculta el widget actual.
    emit show_screen(next_scene); //Muestra el widget siguiente.
    current_scene = next_scene; //Establece el widget siguiente como el widget actual.
}
