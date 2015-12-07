#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "EventManager.h"
#include "Action/MoveAction.h"
#include "SpriteFactory.h"
#include "FactoryConfig/CirnoConfig.h"

#define MS_SPRITE_FPS 64

const std::string defaultResourcePath("resource/spriteSheet");

int main(){
	sf::RenderWindow window(sf::VideoMode(800, 600), "Frame's Title");
	window.setVerticalSyncEnabled(true);
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


	SpriteFactory cirnoFactory(defaultResourcePath);
	CirnoConfig cirnoConfigTemplate;
	cirnoFactory.addConfig(cirnoConfigTemplate);
	AnimatedSprite cirno = cirnoFactory.create("cirno");
	cirno.setOrigin(16,16);
	cirno.setPosition(50,50);

	ConfigObject grownCirnoConfigTemplate("grownCirno","cirnoGrown.png");
	cirnoFactory.addConfig(grownCirnoConfigTemplate);
	AnimatedSprite grownCirno = cirnoFactory.create("grownCirno");
	grownCirno.setOrigin(16,16);
	grownCirno.setPosition(50,50);

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

		if(eventManager.have(std::string("primary"))){
			MoveAction moveGrownCirno(grownCirno);
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			sf::Vector2i spritePosition(grownCirno.getPosition());
			sf::Vector2i path = mousePosition-spritePosition;
			if(path.x > 1){
				moveGrownCirno.setDirection(MoveAction::RIGHT);
				moveGrownCirno.execute();
			}else if(path.x < 1){
				moveGrownCirno.setDirection(MoveAction::LEFT);
				moveGrownCirno.execute();
			}
			if(path.y > 1){
				moveGrownCirno.setDirection(MoveAction::DOWN);
				moveGrownCirno.execute();
			}else if(path.y < -1){
				moveGrownCirno.setDirection(MoveAction::UP);
				moveGrownCirno.execute();
			}

		}

		sf::Time current = clock.getElapsedTime();
		sf::Time elapsed = current - previous;
		previous = current;
		lag += elapsed;

		if(lag.asMilliseconds() >= MS_SPRITE_FPS){
			cirno.nextAnimation();
			grownCirno.nextAnimation();
			lag -= sf::milliseconds(MS_SPRITE_FPS);
		}

		window.clear();

		window.setView(up);
		window.draw(bgUp);
		window.draw(grownCirno);

		window.setView(down);
		window.draw(bgDown);
		window.draw(cirno);

		window.display();
	}

	return 0;
}

