#include "KeyboardMenagement.hpp"

KeyboardMenagement::KeyboardMenagement(sf::RenderWindow *window, sf::Event *event) {
    this->window = window;
    this->event = event;
}

KeyboardMenagement::~KeyboardMenagement() {

}

void KeyboardMenagement::closing_window_case(){
     if(event->type == sf::Event::Closed){
         window->close();
     }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        window->close();
    }
}

void KeyboardMenagement::closing_while_playing_case(Texts *texts){
    if(event->type == sf::Event::Closed){
        window->close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        texts->play_clicked = 0;
    }
}