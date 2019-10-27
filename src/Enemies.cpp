#include "Enemies.hpp"

Enemies::Enemies(sf::RenderWindow *window, int amount_of_enemies) {
    this->window = window;
    this->amount_of_enemies = amount_of_enemies;
    prepare_texture();
    this->enemies_speed = 20;
    this->direction = 1;
    this->amount_in_row = 9;
    this->previous_direction = 1;
    prepare_enemies_vector();
    
}

Enemies::~Enemies() {

}

sf::Texture Enemies::texture = sf::Texture();

void Enemies::prepare_texture(){
    if(!texture.loadFromFile("Textures/drewno3.jpg")){
        std::cout<<"ERROR: loading enemies texture failure!"<<std::endl;
    }
}

sf::Sprite Enemies::prepare_sprite(){
    static sf::Sprite sprite;
    sprite.setTexture(texture);
    return sprite;
}

void Enemies::prepare_enemies_vector(){
    enemies_vector.clear();
    int row_nr = 0;
    for(int i = 0; i < amount_of_enemies; i++){
        if(i % amount_in_row == 0){
            row_nr ++;
        }
        enemies_vector.push_back(new Foe(window, prepare_sprite(),
        sf::Vector2f(window->getSize().x/11 *((i % amount_in_row)+1),
        window->getSize().y/8 * row_nr), enemies_speed));
    }
}

void Enemies::draw_enemies(){
    for(int i = 0; i < amount_of_enemies; i++){
        enemies_vector[i]->draw_foe();
    }
}

void Enemies::move_enemies(){
    if(direction == 1){
        move_right_case();
    }
    else{
        if(direction == 2){
        move_left_case();
    }
    else{
        if(direction == 0){
        move_down_case();
    }
    }
    }
    

}

void Enemies::move_right_case(){
    previous_direction = 1;
    if(amount_of_enemies >= amount_in_row){
            if(enemies_vector[amount_in_row - 1]->get_position().x +
            enemies_vector[amount_in_row - 1]->get_size()/2 <= window->getSize().x -
            enemies_speed*2){
                for(int i = 0; i < amount_of_enemies; i++){
                    enemies_vector[i]->move_right();
                }
            }
            else{
                direction = 0;
            }
        }
    else{
        if(enemies_vector[amount_of_enemies - 1]->get_position().x +
            enemies_vector[amount_of_enemies - 1]->get_size()/2 <= window->getSize().x -
            enemies_speed*2){
                for(int i = 0; i < amount_of_enemies; i++){
                    enemies_vector[i]->move_right();
                }
            }
            else{
                direction = 0;
            }
    }
}

void Enemies::move_left_case(){
    previous_direction = 2;
    if(amount_of_enemies > 0){
        if(enemies_vector[0]->get_position().x -
        enemies_vector[0]->get_size()/2 >= enemies_speed * 2){
            for(int i = 0; i < amount_of_enemies; i++){
                enemies_vector[i]->move_left();
            }
        }
        else{
            direction = 0;
        }
    }
    else{
        std::cout<<"THERE ARE NO MORE ENEMIES(Enemies::move_left_case() error!"<<std::endl;
    }
}

void Enemies::move_down_case(){
    //Przypadek kiedy są za nisko
    // if(enemies_vector[amount_of_enemies - 1]->get_position().y + 
    // enemies_vector[amount_of_enemies - 1]->get_size/2 <=
    // window->getSize().y/3){
    // }
    for(int i = 0; i < amount_of_enemies; i++){
        enemies_vector[i]->move_down();
    }
    if(previous_direction == 1){
        direction = 2;
    }
    if(previous_direction == 2){
        direction = 1;
    }

}