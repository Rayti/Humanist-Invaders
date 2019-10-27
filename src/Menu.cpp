#include "Menu.hpp"
#include <SFML/Graphics.hpp>

Menu::Menu(sf::RenderWindow *window) {
    this->window = window;
    this->keyboard_menagement = new KeyboardMenagement(window, &event);
    this->player = new Player(window);
    this->enemies = new Enemies(window, 18);
    this->texts = new Texts(window, &event);
}

Menu::~Menu() {

}

void Menu::start(){

    program_loop();

}  

void Menu::game(){
    while(window->pollEvent(event)){
            keyboard_menagement->closing_while_playing_case(texts);
            player->player_movement();
        }
    if(elapsed.asMilliseconds() >= 150){
        enemies->move_enemies();
        clock.restart();
    }    
    player->draw_player();
    enemies->draw_enemies();
}

void Menu::options(){
    while(window->pollEvent(event)){
        keyboard_menagement->closing_window_case();
        texts->button_play_text();
        texts->button_exit_text();
        texts->button_scores_text();
    }
    texts->draw_texts();
}

void Menu::program_loop(){
    clock = sf::Clock();
    while(window->isOpen()){
        window->clear(sf::Color::Yellow);
        elapsed = clock.getElapsedTime();
        if(!texts->play_clicked){
            options();
        }
        if(texts->play_clicked){
            game();
        }
        if(texts->exit_clicked){
            window->close();
        }
        if(texts->scores_clicked){
            //DODAC WCZYTYWANIE WYNIKOW Z PLIKU
        }
        window->display();
    }


}