#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Foe {

public:
    Foe(sf::RenderWindow *window, sf::Sprite sprite, sf::Vector2f position, int speed);
    ~Foe();
    bool is_alive();
    void draw_foe();
    void move_right();
    void move_left();
    void move_down();
    sf::Vector2f get_position();
    int get_size();
private:
    sf::RenderWindow *window;
    sf::Vector2f position;
    int size;
    int hp;
    int speed;
    sf::Sprite sprite;
};