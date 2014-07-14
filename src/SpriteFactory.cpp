#include <SFML/Graphics.hpp>
#include "SpriteFactory.h"

SpriteFactory::SpriteFactory(std::string path) : path_(path){}

AnimatedSprite SpriteFactory::create(std::string spriteSheetName){
	sf::Texture spriteSheet;
	spriteSheet.loadFromFile(path_ + "/" + spriteSheetName);
	AnimatedSprite sprite(spriteSheet);
	for(std::pair<std::string, Animation> animation : animationList_){
		sprite.addAnimation(animation.first, animation.second);
	}
	return AnimatedSprite(spriteSheet);
}

void SpriteFactory::addAnimation(std::string animationName, Animation& animation){
	animationList_[animationName] = animation;
}

