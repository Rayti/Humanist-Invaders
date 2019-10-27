#include "Texts.hpp"
#include <iostream>

Texts::Texts(sf::RenderWindow *window, sf::Event *event){
    this->window = window;
    this->event = event;
    this->play_clicked = 0;
    this->exit_clicked = 0;
    this->scores_clicked = 0;
    if(!font1.loadFromFile("Fonts/BUBBLEBATH.ttf")){
        std::cout<<"ERROR: loading player texture failure!"<<std::endl;
    }
    prepare_main_title();
    prepare_play_text();
    prepare_scores_text();
    prepare_exit_text();
    
}

Texts::~Texts(){

}

void Texts::draw_texts(){
    window->draw(main_title);
    window->draw(play_text);
    window->draw(scores_text);
    window->draw(exit_text);
}

void Texts::prepare_main_title(){
    main_title.setFont(font1);
    main_title.setString("Humanist Invaders");
    main_title.setFillColor(sf::Color::Black);
    main_title.setCharacterSize(90);
    main_title.setOrigin(main_title.getGlobalBounds().left +
    main_title.getGlobalBounds().width/2,
    main_title.getGlobalBounds().top +
    main_title.getGlobalBounds().height/2);
    main_title.setPosition(window->getSize().x/2, window->getSize().y/4);
}

void Texts::prepare_play_text(){
    play_text.setFont(font1);
    play_text.setString("Play");
    play_text.setFillColor(sf::Color::Black);
    play_text.setCharacterSize(55);
    play_text.setOrigin(play_text.getGlobalBounds().left +
    play_text.getGlobalBounds().width/2,
    play_text.getGlobalBounds().top +
    play_text.getGlobalBounds().height/2);
    play_text.setPosition(window->getSize().x/2, window->getSize().y/4 * 2);
}

void Texts::prepare_scores_text(){
    scores_text.setFont(font1);
    scores_text.setString("Scores");
    scores_text.setFillColor(sf::Color::Black);
    scores_text.setCharacterSize(55);
    scores_text.setOrigin(scores_text.getGlobalBounds().left +
    scores_text.getGlobalBounds().width/2,
    scores_text.getGlobalBounds().top +
    scores_text.getGlobalBounds().height/2);
    scores_text.setPosition(window->getSize().x/2, window->getSize().y/4 * 2.5);
}

void Texts::prepare_exit_text(){
    exit_text.setFont(font1);
    exit_text.setString("Exit");
    exit_text.setFillColor(sf::Color::Black);
    exit_text.setCharacterSize(55);
    exit_text.setOrigin(exit_text.getGlobalBounds().left +
    exit_text.getGlobalBounds().width/2,
    exit_text.getGlobalBounds().top +
    exit_text.getGlobalBounds().height/2);
    exit_text.setPosition(window->getSize().x/2, window->getSize().y/4 * 3);
}

void Texts::button_play_text(){
    if(event->type == sf::Event::MouseButtonPressed){
        if(event->mouseButton.button == sf::Mouse::Left){
            if(event->mouseButton.x >= play_text.getPosition().x - 
            play_text.getGlobalBounds().width/2 &&
            event->mouseButton.x <= play_text.getPosition().x + 
            play_text.getGlobalBounds().width/2 &&
            event->mouseButton.y >= play_text.getPosition().y - 
            play_text.getGlobalBounds().height/2 &&
            event->mouseButton.y <= play_text.getPosition().y + 
            play_text.getGlobalBounds().height/2){
                play_clicked = 1;
            }
        }
    }

}

void Texts::button_exit_text(){
    if(event->type == sf::Event::MouseButtonPressed){
        if(event->mouseButton.button == sf::Mouse::Left){
            if(event->mouseButton.x >= exit_text.getPosition().x - 
            exit_text.getGlobalBounds().width/2 &&
            event->mouseButton.x <= exit_text.getPosition().x + 
            exit_text.getGlobalBounds().width/2 &&
            event->mouseButton.y >= exit_text.getPosition().y - 
            exit_text.getGlobalBounds().height/2 &&
            event->mouseButton.y <= exit_text.getPosition().y + 
            exit_text.getGlobalBounds().height/2){
                exit_clicked = 1;
            }
        }
    }
}

void Texts::button_scores_text(){
    if(event->type == sf::Event::MouseButtonPressed){
        if(event->mouseButton.button == sf::Mouse::Left){
            if(event->mouseButton.x >= scores_text.getPosition().x - 
            scores_text.getGlobalBounds().width/2 &&
            event->mouseButton.x <= scores_text.getPosition().x + 
            scores_text.getGlobalBounds().width/2 &&
            event->mouseButton.y >= scores_text.getPosition().y - 
            scores_text.getGlobalBounds().height/2 &&
            event->mouseButton.y <= scores_text.getPosition().y + 
            scores_text.getGlobalBounds().height/2){
                if(!scores_clicked){
                    scores_text.setFillColor(sf::Color::Blue);
                    scores_clicked = 1;
                }
                else{
                    scores_text.setFillColor(sf::Color::Black);
                    scores_clicked = 0;
                }
                
            }
        }
    }
}

void Texts::button_main_title(){

}