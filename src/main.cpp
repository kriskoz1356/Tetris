#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
int main() {
    sf::RenderWindow window(
        sf::VideoMode({ 800,600 }), "Tytuł"
    );
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
    // cout << "Hello World!" << endl;
    return 0;
}