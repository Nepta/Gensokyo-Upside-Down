#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Frame's Title");
    sf::Texture backgroundTexture;
    sf::Sprite background;

    backgroundTexture.loadFromFile("resource/map/littleForest.png");
    background.setTexture(backgroundTexture);
    background.setOrigin(0.f,0.f);
    
    sf::Texture cirnoSheet;
    cirnoSheet.loadFromFile("resource/spriteSheet/WZcSP.png", {96,0,96,128});
    sf::Sprite cirno(cirnoSheet);
    cirno.setTextureRect({0,0,32,32});
    cirno.setOrigin(16,16);
    cirno.setPosition(350,540);

    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        
        window.clear();
        window.draw(background);
        window.draw(cirno);
        window.display();
    }

    return 0;
}
