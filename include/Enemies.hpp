#pragma once
#include <SFML/Graphics.hpp>
#include <Foe.hpp>
#include <vector>
#include <iostream>

class Enemies {

public:
    Enemies(sf::RenderWindow *window, int amount_of_enemies);
    ~Enemies();
    void draw_enemies();
    void move_enemies();

private:
    std::vector <Foe*> enemies_vector;
    sf::RenderWindow *window;
    static sf::Texture texture;
    int amount_of_enemies;
    void prepare_enemies_vector();
    static void prepare_texture();
    static sf::Sprite prepare_sprite();
    int direction; //1 = right, 2 = left, 0 = down
    int previous_direction;
    int amount_in_row;
    int enemies_speed;
    void move_right_case();
    void move_left_case();
    void move_down_case();
};