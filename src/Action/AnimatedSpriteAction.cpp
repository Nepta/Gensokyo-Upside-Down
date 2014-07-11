#include "AnimatedSpriteAction.h"
#include <SFML/Graphics.hpp>

AnimatedSpriteAction::AnimatedSpriteAction(AnimatedSprite& sprite) : SpriteAction(sprite){}

AnimatedSprite& AnimatedSpriteAction::sprite(){
	sf::Sprite& sprite = SpriteAction::sprite();
	return dynamic_cast<AnimatedSprite&>(sprite);
}
