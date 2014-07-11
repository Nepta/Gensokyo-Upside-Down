#ifndef __SpriteAction_H__
#define __SpriteAction_H__

#include <SFML/Graphics.hpp>

class SpriteAction{
	sf::Sprite& sprite_;
	
public:
	SpriteAction(sf::Sprite& sprite);
	virtual sf::Sprite& sprite();
	virtual void execute() = 0;
};

#endif /* __SpriteAction_H__ */

