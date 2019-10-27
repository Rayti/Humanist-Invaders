#include "Player.hpp"
#include <iostream>

Player::Player(sf::RenderWindow *window) {
    this->window = window;
    this->size = 100;
    this->speed = 10;
    this->hp = 3;
    this->position.x = window->getSize().x/2;
    this->position.y = window->getSize().y/10 * 9;
    if(!texture.loadFromFile("Textures/drewno3.jpg")){
        std::cout<<"ERROR: loading player texture failure!"<<std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, size, size));
    sprite.setOrigin(size/2, size/2);
    sprite.setPosition(position);
}

Player::~Player() {

}

void Player::draw_player(){
    window->draw(sprite);
}

void Player::move_left(){
    position.x -= speed;
    sprite.setPosition(position);
}

void Player::move_right(){
    position.x += speed;
    sprite.setPosition(position);
}

void Player::player_movement(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        move_left();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        move_right();
    }
}