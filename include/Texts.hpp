#pragma once
#include <SFML/Graphics.hpp>

class Texts {

public:
    Texts(sf::RenderWindow *window, sf::Event *event);
    ~Texts();
    void draw_texts();
    void button_main_title();
    void button_play_text();
    void button_exit_text();
    void button_scores_text();
    bool play_clicked;
    bool exit_clicked;
    bool scores_clicked;
private:
    sf::Font font1;
    sf::RenderWindow *window;
    sf::Event *event;
    sf::Text main_title;
    sf::Text play_text;
    sf::Text scores_text;
    sf::Text exit_text;
    //
    void prepare_main_title();
    void prepare_play_text();
    void prepare_scores_text();
    void prepare_exit_text();
    //

};