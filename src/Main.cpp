#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "EventManager.h"
#include "Action/MoveAction.h"

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
    AnimatedSprite cirno(cirnoSheet);
    cirno.addAnimation({0,0,32,32});
    cirno.addAnimation({32,0,32,32});
    cirno.addAnimation({64,0,32,32});
    cirno.setOrigin(16,16);
    cirno.setPosition(350,540);
    
    
    int i = 350;
    while(window.isOpen()){
        sf::Event event;
        EventManager eventManager;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }else{
            	eventManager.addEvent(event);
            }
        }
        if(eventManager.have(std::string("right"))){
        	SpriteAction *moveCirno = (new MoveAction(cirno))->setDirection(MoveAction::RIGHT);
        	moveCirno->execute();
//        	cirno.setPosition(i++,540);
        }
        cirno.nextAnimation();
        window.clear();
        window.draw(background);
        window.draw(cirno);
        window.display();
    }

    return 0;
}

