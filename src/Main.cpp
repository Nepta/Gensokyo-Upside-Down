#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "EventManager.h"
#include "Action/MoveAction.h"
#include "SpriteFactory.h"

#define MS_SPRITE_FPS 64

AnimatedSprite getCirno(){
	SpriteFactory& cirnoFactory = *(new SpriteFactory("resource/spriteSheet"));
	cirnoFactory.addSpriteSheet("cirno.png");
	
	Animation cirnoDown{{0,0,32,32},{32,0,32,32},{64,0,32,32}};
	Animation cirnoLeft{{0,32,32,32},{0,32,32,32},{64,32,32,32}};
	Animation cirnoRight{{0,64,32,32},{32,64,32,32},{64,64,32,32}};
	Animation cirnoUp{{0,96,32,32},{32,96,32,32},{64,96,32,32}};
	
	cirnoFactory.addAnimation("down",cirnoDown);
	cirnoFactory.addAnimation("left",cirnoLeft);
	cirnoFactory.addAnimation("right",cirnoRight);
	cirnoFactory.addAnimation("up",cirnoUp);

	AnimatedSprite cirno = cirnoFactory.create("cirno.png");
	cirno.setOrigin(16,16);
	cirno.setPosition(50,50);
	return cirno;
}

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "Frame's Title");
	sf::Texture backgroundTexture;
	sf::Sprite background;

	backgroundTexture.loadFromFile("resource/map/littleForest.png");
	background.setTexture(backgroundTexture);
	background.setOrigin(0.f,0.f);

	sf::Texture texBgUp;
	texBgUp.loadFromFile("resource/map/bg_up.png");
	sf::Sprite bgUp(texBgUp);

	sf::Texture texBgDown;
	texBgDown.loadFromFile("resource/map/bg_down.png");
	sf::Sprite bgDown(texBgDown);

	sf::View up(
        sf::FloatRect(
            0.f, 
            0.f, 
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y/2) 
        )
    );
	up.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 0.5f));

	sf::View down(
        sf::FloatRect(
            0.f, 
            0.f, 
            static_cast<float>(window.getSize().x),
            static_cast<float>(window.getSize().y/2)
        )
    );
	down.setViewport(sf::FloatRect(0.f, 0.5f, 1.f, 0.5f));

	AnimatedSprite cirno = getCirno();
	
	EventManager eventManager;

	sf::Clock clock;
	sf::Time previous = clock.getElapsedTime();
	sf::Time lag = sf::Time::Zero;

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}else{
				eventManager.addEvent(event);
			}
		}
		MoveAction moveCirno(cirno);
		if(eventManager.have(std::string("right"))){
			moveCirno.setDirection(MoveAction::RIGHT);
			moveCirno.execute();
		}
		if(eventManager.have(std::string("left"))){
			moveCirno.setDirection(MoveAction::LEFT);
			moveCirno.execute();
		}
		if(eventManager.have(std::string("up"))){
			moveCirno.setDirection(MoveAction::UP);
			moveCirno.execute();
		}
		if(eventManager.have(std::string("down"))){
			moveCirno.setDirection(MoveAction::DOWN);
			moveCirno.execute();
		}

		sf::Time current = clock.getElapsedTime();
		sf::Time elapsed = current - previous;
		previous = current;
		lag += elapsed;

		if(lag.asMilliseconds() >= MS_SPRITE_FPS){
			cirno.nextAnimation();
			lag -= sf::milliseconds(MS_SPRITE_FPS);
		}

		window.clear();

		window.setView(up);
		window.draw(bgUp);
		window.setView(down);
		window.draw(bgDown);

		window.draw(cirno);
		window.display();
	}

	return 0;
}

