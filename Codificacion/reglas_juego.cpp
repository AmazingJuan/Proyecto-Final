#include "reglas_juego.h"
#include "utilities.h"

reglas_juego::reglas_juego(QVector<QGraphicsView *> &graphics, QVector<QPushButton *> &shop_buttons, partida *partida)
{
    this -> shop_buttons = shop_buttons;
    ship = nullptr;
    seed = std::chrono::system_clock::now().time_since_epoch().count();
    next_scene = -1;
    in_scene_obstacles = 0;
    random_int_range = 0;
    twister_death = false;
    current_stage = 1;
    current_scene = -1;
    change_scene_timer = new QTimer;
    wave_timer = new QTimer;
    game_timer = new QTimer;
    dispatch_obstacles_timer = new QTimer;
    interfaces = graphics;
    saves = partida;
    shop_prices[0] = 100;
    shop_prices[1] = 600;
    shop_prices[2] = 1000;
    initial_conections();
    stage_messages.push_back(stage_1);
    stage_messages.push_back(stage_2);
    stage_messages.push_back(stage_3);

    reproductor = new QMediaPlayer;
    output = new QAudioOutput;
    reproductor -> setAudioOutput(output);
}

void reglas_juego::main_menu(){
    emit show_screen(main_menu_scene);
    current_scene = 0;
    show_image(scenes[current_scene], QString(":/imagenes/Imagenes/menuppal.png"));
}

void reglas_juego::main_menu_load()
{
    emit show_screen(main_menu_load_scene);
    current_scene = 1;
    show_image(scenes[current_scene], QString(":/imagenes/Imagenes/menuppal_carga.png"));
    play_music("qrc:/audio/Audios/intro.mp3", reproductor, output, false);
}

reglas_juego::~reglas_juego()
{
    delete saves;
    delete change_scene_timer;
    delete ship;
    delete reproductor;
    delete output;
    dispose_obstacles();
    dispose_shop_obstacles();
}

void reglas_juego::setup()
{
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
        interfaces[indice]->setScene(scenes[indice]);
        indice++;
    }
    scenes[2] -> setBackgroundBrush(Qt::black);
    saves->exists_file();
}

void reglas_juego::key_pressed(int key)
{
    if(current_scene == 3){
        if(key == Qt::Key_W){
            ship -> move(0);
            emit change_speed(1);
        }
        else if(key == Qt::Key_A){
            ship -> move(1);
        }
        else if(key == Qt::Key_D){
            ship -> move(2);
        }
        else if(key == Qt::Key_S){
            emit change_speed(-1);
        }
        else if(key == Qt::Key_Escape){
            handle_menu_compra();
        }
    }
    else if(current_scene == 4 && key == Qt::Key_Escape) handle_menu_compra();
}

void reglas_juego::obstacle_connections(obstaculo *obstacle)
{
    connect(obstacle, &obstaculo::ask_move, this, &reglas_juego::try_move);
    connect(this, &reglas_juego::crash, obstacle, &obstaculo::start_crash);
    connect(this, &reglas_juego::change_speed, obstacle, &obstaculo::change_speed);
    connect(obstacle, &obstaculo::surpassed_limit, this, &reglas_juego::outside_removal);
}

void reglas_juego::cargar()
{

}

void reglas_juego::start_game()
{
    saves -> save_load();
    if(!saves -> getError()){
        QVector<int> data = saves -> getData();
        unsigned short level = data[0], coins = data[1], stage = data[2], hp = data[3], time = data[4];
        current_stage = stage;
        game_time_counter = time;
        ship = new barco(level, hp, 300 , 400);
        ship -> setMoney(coins);
        scenes[3] -> addItem(ship);
        setup_shop();
        show_middle_message(stage_messages[current_stage - 1]);
        next_scene = 3;
    }
}

void reglas_juego::change_scene()
{
    switch_scenes();
    current_scene = next_scene;
    change_scene_timer -> stop();
    if(current_scene == 3 && !twister_death){
        if(current_stage >= 2) wave_timer -> start(30000);
        setup_stage();
        game_timer->start(1000);
        play_music("qrc:/audio/Audios/stage_" +  QString::number(current_stage) + ".mp3", reproductor, output, false);
    }
    else if(current_scene == 3 && twister_death){
        show_image(scenes[3], ":/imagenes/Imagenes/twister.png");
        ship -> setX(350);
        ship -> setY(150);
        play_music("qrc:/audio/Audios/twister.ogg", reproductor, output, false);
        emit mcu();
    }
}

void reglas_juego::timer_changed()
{
    game_time_counter--;
    emit shoot_label_change(6, "TIEMPO RESTANTE: " + QString::number(game_time_counter), false);
    if(game_time_counter == 0){
        handle_end_stage();
    }
}

void reglas_juego::handle_mcu_finish()
{
    gameover();
}

void reglas_juego::loadMenu(bool dato)
{
    if(dato) main_menu_load();
    else main_menu();

}

void reglas_juego::try_move(QPoint pos, QGraphicsProxyWidget *widget, bool crash_happening)
{
    obstaculo *cast = dynamic_cast<obstaculo *>(widget);
    bool aux = is_colliding(widget);
    if(pos.x() <= 600 && pos.x() >= 0){
        if(!crash_happening){
            if(!aux){
                widget->setX(pos.x());
                widget->setY(pos.y());
            }
            else{
                if(cast -> getIs_dangerous()){
                    if(cast ->getIs_twister()){
                        stop_game();
                        emit shoot_label_change(5, "", false);
                        emit shoot_label_change(6, "", false);
                        twister_death = true;
                        show_middle_message("Vaya...\nHas caido en un\nTORNADO.");
                    }
                    else if(ship -> getHp() - cast -> getIssued_damage() > 0){
                        emit crash(widget);
                        emit crash_ship(cast -> getSpeed());
                        ship -> setHp(ship -> getHp() - cast -> getIssued_damage());
                        emit shoot_label_change(5, "HP: " + QString::number(ship -> getHp()), false);
                        saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter);
                        cast -> play_own_music();
                    }
                    else{
                        gameover();
                    }
                }
                else{
                    cast -> play_own_music();
                    outside_removal(cast);
                    ship -> addMoney(random_short(min_money_per_coin, max_money_per_coin, seed));
                    saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter);
                }
            }
        }
        else{
            widget->setX(pos.x());
            widget->setY(pos.y());
        }
    }
}

void reglas_juego::dispatch_obstacles()
{
    if(in_scene_obstacles < (current_stage + 1)){
        unsigned short columna = random_short(0, 6, seed);
        if(random_bool(seed)) moving_obstacles.push_back(new obstaculo(9, ship -> getMass(), ship -> getShip_force(), 100));
        else if(current_stage == 3 && random_short(0,10,seed) >= 7) moving_obstacles.push_back(new obstaculo(9, ship -> getMass(), ship -> getShip_force(), 100));
        else moving_obstacles.push_back(new obstaculo(random_short(1,current_stage, seed), ship -> getMass(), ship -> getShip_force(), 100));
        scenes[3] -> addItem(moving_obstacles[moving_obstacles.size() - 1]);
        moving_obstacles[moving_obstacles.size() - 1] -> setX(columna * 100);
        moving_obstacles[moving_obstacles.size() - 1] -> setY(-100);
        obstacle_connections(moving_obstacles[moving_obstacles.size() - 1]);
        moving_obstacles[moving_obstacles.size() - 1]->start_movement();
        in_scene_obstacles++;
    }
}

void reglas_juego::wave_event()
{
    emit shm();
    //REPRODUCIR SONIDO DE OLEAJE
}

void reglas_juego::handle_end_stage()
{
    current_stage += 1;
    if(current_stage != 4){
        game_timer -> stop();
        if(wave_timer -> isActive()) wave_timer -> stop();
        dispatch_obstacles_timer->stop();
        ship -> stop_movement();
        dispose_obstacles();
        in_scene_obstacles = 0;
        show_middle_message(stage_messages[current_stage - 1]);
        next_scene = 3;
    }
    else{
        win();
    }
}

void reglas_juego::gameover()
{
    stop_game();
    play_music("qrc:/audio/Audios/gameover.ogg", reproductor, output, false);
    scenes[3] -> removeItem(ship);
    next_scene = 2;
    switch_scenes();
    emit shoot_button_change(0);
    show_image(scenes[2], ":/imagenes/Imagenes/gameover.png");
    emit shoot_label_change(0, "", false);
}

void reglas_juego::win()
{
    stop_game();
    play_music("qrc:/audio/Audios/victory.mp3", reproductor, output, false);
    scenes[3] -> removeItem(ship);
    next_scene = 2;
    switch_scenes();
    emit shoot_button_change(0);
    show_image(scenes[2], ":/imagenes/Imagenes/win.png");
    emit shoot_label_change(0, "", false);
}

void reglas_juego::stop_game()
{
    dispose_obstacles();
    game_timer -> stop();
    change_scene_timer -> stop();
    wave_timer -> stop();
    dispatch_obstacles_timer -> stop();
    ship -> stop_movement();
}


void reglas_juego::manage_shop_buttons()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    unsigned short index = shop_buttons.indexOf(button);
    if(ship -> getMoney() >= shop_prices[index] && index + 2 > ship -> getLevel()){
        ship -> setMoney(ship -> getMoney() - shop_prices[index]);
        handle_menu_compra();
        ship -> level_up(index + 2);
        update_shop(index + 1);
        saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter);
        shop_obstacles[0] -> play_own_music();
    }
    else{
        shop_obstacles[1] -> play_own_music();
    }
}

void reglas_juego::show_middle_message(QString text)
{
    change_scene_timer -> start(15000);
    next_scene = 2;
    switch_scenes();
    next_scene = 3;
    emit shoot_label_change(0, text, true);
    if(!twister_death) play_music("qrc:/audio/Audios/middle.wav", reproductor, output, false);
    else play_music("qrc:/audio/Audios/twister_middle.mp3", reproductor, output, false);
}

void reglas_juego::handle_menu_compra()
{
    update_shop(ship -> getLevel() - 1);
    if(current_scene == 3) next_scene = 4;
    else next_scene = 3;
    switch_scenes();
}

void reglas_juego::update_shop(unsigned short blocked)
{
    int price = 0;
    unsigned short cont = 0;
    for(; cont < 3; cont++){
        if(cont + 1<= blocked){
            emit shoot_label_change(cont + 1, "", true);
            price += shop_prices[cont];
            shop_prices[cont] = 0;
        }
        else{
            QString aux = QString::number(shop_prices[cont] - price);
            shop_prices[cont] = shop_prices[cont] - price;
            emit shoot_label_change(cont + 1, aux, true);
        }
    }
    emit shoot_label_change(cont + 1, QString(QString::number(ship -> getMoney()) + " COINS" ), false);
}

void reglas_juego::initial_conections()
{
    connect(saves, &partida::exists_save, this, &reglas_juego::loadMenu);
    connect(change_scene_timer, &QTimer::timeout, this, &reglas_juego::change_scene);
    connect(dispatch_obstacles_timer, &QTimer::timeout, this, &reglas_juego::dispatch_obstacles);
    connect(wave_timer, &QTimer::timeout, this, &reglas_juego::wave_event);
    connect(game_timer, &QTimer::timeout, this, &::reglas_juego::timer_changed);
}

void reglas_juego::stage_connections()
{
    connect(ship, &barco::ask_move, this, &reglas_juego::try_move);
    connect(ship, &barco::mcu_finished, this, &reglas_juego::handle_mcu_finish);
    connect(this, &reglas_juego::shm, ship, &barco::start_shm);
    connect(this, &reglas_juego::crash_ship, ship, &barco::start_crash);
    connect(this, &reglas_juego::mcu, ship, &barco::start_mcu);
}

bool reglas_juego::is_colliding(QGraphicsProxyWidget *widget)
{
    if(widget != ship){
        QPointF pos_ship = ship->pos();
        QPointF pos_widget = widget->pos();
        pos_ship .setX(pos_ship.x() + 50);
        pos_ship .setY(pos_ship.y() + 50);
        pos_ship .setX(pos_widget.x() + 50);
        pos_ship .setY(pos_widget.y() + 50);
        return calculate_distance(ship->pos(), widget->pos()) < 60;
    }
    else{
        return false;
    }
}

void reglas_juego::dispose_obstacles()
{
    for(int cont = moving_obstacles.size() - 1; cont >= 0; cont--){
        moving_obstacles[cont] -> stop_movement();
        scenes[3]-> removeItem(moving_obstacles[cont]);
        removed_obstacles.push_back(moving_obstacles[cont]);
        moving_obstacles.removeOne(moving_obstacles[cont]);
    }
    dispose_removed_obstacles();
}

void reglas_juego::dispose_removed_obstacles()
{
    for(int cont = 0; cont < removed_obstacles.size(); cont++){
        delete removed_obstacles[cont];
        removed_obstacles.remove(cont);
    }
}

void reglas_juego::dispose_shop_obstacles()
{
    for(int cont = 0; cont < shop_obstacles.size(); cont++){
        delete shop_obstacles[cont];
    }
    shop_obstacles.clear();
}

void reglas_juego::outside_removal(obstaculo *obs)
{
    in_scene_obstacles -= 1;
    scenes[3] -> removeItem(obs);
    moving_obstacles.removeOne(obs);
    removed_obstacles.push_back(obs);
    obs -> stop_movement();
}

void reglas_juego::setup_stage()
{
    if(game_time_counter == 0)game_time_counter = game_duration;
    ship -> setX(300);
    ship -> setY(400);
    show_image(scenes[3], ":/imagenes/Imagenes/fondo_" + QString::number(current_stage) + ".jpg");
    update_shop(ship -> getLevel() - 1);
    dispatch_obstacles_timer -> start(4000);
    stage_connections();
    emit shoot_label_change(5, QString("HP:" + QString::number(ship -> getHp())), false);
    saves -> update_data(ship -> getLevel(), ship -> getMoney(), current_stage, ship -> getHp(), game_time_counter);
}

void reglas_juego::setup_shop()
{
    show_image(scenes[4], ":/imagenes/Imagenes/menucompra.png");
    unsigned int var = 0;
    for(unsigned short cont = 0; cont < 3; cont++) {
        shop_obstacles.push_back(new obstaculo(6 + cont, 0, 0, 130));
        shop_obstacles[cont] -> setX(390);
        if(cont == 0) var = 70;
        else if(cont == 1) var = 241;
        else var = 413;
        shop_obstacles[cont] -> setY(var);
        scenes[4] -> addItem(shop_obstacles[cont]);
    }
}

void reglas_juego::switch_scenes()
{
    emit hide_screen(current_scene);
    emit show_screen(next_scene);
    current_scene = next_scene;
}

