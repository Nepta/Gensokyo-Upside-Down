#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "EventManager.h"
#include "Action/MoveAction.h"

void initCirno(AnimatedSprite& cirno){
	Animation cirnoDown;
	cirnoDown.addAnimation({0,0,32,32});
	cirnoDown.addAnimation({32,0,32,32});
	cirnoDown.addAnimation({64,0,32,32});
	
	Animation cirnoLeft;
	cirnoLeft.addAnimation({0,32,32,32});
	cirnoLeft.addAnimation({32,32,32,32});
	cirnoLeft.addAnimation({64,32,32,32});
	
	Animation cirnoRight;
	cirnoRight.addAnimation({0,64,32,32});
	cirnoRight.addAnimation({32,64,32,32});
	cirnoRight.addAnimation({64,64,32,32});
	
	Animation cirnoUp;
	cirnoUp.addAnimation({0,96,32,32});
	cirnoUp.addAnimation({32,96,32,32});
	cirnoUp.addAnimation({64,96,32,32});
	
	cirno.addAnimation("down",cirnoDown);
	cirno.addAnimation("left",cirnoLeft);
	cirno.addAnimation("right",cirnoRight);
	cirno.addAnimation("up",cirnoUp);
	
	cirno.setOrigin(16,16);
	cirno.setPosition(350,540);
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

	sf::View gui = window.getView();

	sf::View up(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().y/2), static_cast<float>(window.getSize().x)));
	up.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 0.998f));
	sf::View down(sf::FloatRect(0.f, 0.f, static_cast<float>(window.getSize().y/2), static_cast<float>(window.getSize().x)));
	down.setViewport(sf::FloatRect(0.f, 0.502f, 1.f, 1.f));

	sf::Texture cirnoSheet;
	cirnoSheet.loadFromFile("resource/spriteSheet/WZcSP.png", {96,0,96,128});
	AnimatedSprite cirno(cirnoSheet);
	initCirno(cirno);
	
	EventManager eventManager;
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
		cirno.nextAnimation();
		window.clear();

		window.setView(up);
		window.draw(bgUp);
		window.setView(down);
		window.draw(bgDown);

		window.setView(gui);
		window.draw(cirno);
		window.display();
	}

	return 0;
}

