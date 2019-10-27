#pragma once
#include <SFML/Graphics.hpp>

class Player {

public:
    Player(sf::RenderWindow *window);
    ~Player();
    void draw_player();
    void player_movement();
private:
    sf::RenderWindow *window;
    sf::Vector2f position;
    int size;
    int hp;
    int speed;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Event event;
    void move_left();
    void move_right();

};