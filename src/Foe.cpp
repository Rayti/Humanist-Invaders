#include "Foe.hpp"
#include <iostream>

Foe::Foe(sf::RenderWindow *window, sf::Sprite sprite, sf::Vector2f position, int speed) {
    this->window = window;
    this->size = 100;
    this->hp = 2;
    this->speed = speed;
    this->position.x = position.x;
    this->position.y = position.y;
    this->sprite = sprite;
    this->sprite.setTextureRect(sf::IntRect(0, 0, size, size));
    this->sprite.setOrigin(size/2, size/2);
    this->sprite.setPosition(position);
}

Foe::~Foe() {

}

    void Foe::draw_foe(){
    if(hp == 1){
       sprite.setColor(sf::Color(230, 30, 30, 100));
    }
    window->draw(sprite);
}

bool Foe::is_alive(){
    if(hp > 0){
        return true;
    }
    else{
        return false;
    }
}

void Foe::move_down(){
    position.y += speed * 2;
    sprite.setPosition(position);
}

void Foe::move_right(){
    position.x += speed;
    sprite.setPosition(position);
}

void Foe::move_left(){
    position.x -= speed;
    sprite.setPosition(position);
}

sf::Vector2f Foe::get_position(){
    return position;
}

int Foe::get_size(){
    return size;
}