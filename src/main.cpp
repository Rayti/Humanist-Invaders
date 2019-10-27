#include <iostream>
#include <SFML/Graphics.hpp>
#include <Menu.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Humanist Invasion", sf::Style::Default);
    Menu menu(&window);
    menu.start();
    
    std::cout << "** PROGRAM ** IS ** WORKING **" << std::endl;
}