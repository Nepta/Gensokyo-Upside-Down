#include "SpriteAction.h"

SpriteAction::SpriteAction(sf::Sprite& sprite) : sprite_(sprite){}

sf::Sprite& SpriteAction::sprite(){
	return sprite_;
}
