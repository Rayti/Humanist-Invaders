#pragma once
#include <SFML/Graphics.hpp>
#include <Texts.hpp>

class KeyboardMenagement {

public:
    KeyboardMenagement(sf::RenderWindow *window, sf::Event *event);
    ~KeyboardMenagement();
    void closing_window_case();
    void closing_while_playing_case(Texts *texts);

private:
    sf::RenderWindow *window;
    sf::Event *event;
};