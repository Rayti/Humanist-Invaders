#pragma once
#include <SFML/Graphics.hpp>
#include <KeyboardMenagement.hpp>
#include <Player.hpp>
#include <Texts.hpp>
#include <Enemies.hpp>
#include <Foe.hpp>

class Menu {

public:
    Menu(sf::RenderWindow *window);
    ~Menu();
    void start();
private:
    KeyboardMenagement *keyboard_menagement;
    sf::RenderWindow *window;
    Texts *texts;
    void program_loop();
    void game();
    void options();
    Player *player;
    Enemies *enemies;
    sf::Event event;
    sf::Clock clock;
    sf::Time elapsed;
};