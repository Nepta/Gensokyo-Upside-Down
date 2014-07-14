#include "SpriteFactory.h"

SpriteFactory::SpriteFactory(std::string path = "") : path_(path){}

AnimatedSprite SpriteFactory::create(std::string spriteSheetName){
	sf::Texture spriteSheet.loadFromFile( path << "/" << spriteSheetName);
	return AnimatedSprite(spriteSheet);
//	initCirno(cirno);
}

void SpriteFactory::addAnimation(std::string animationName, Animation& animation){
	animationList_[animationName] = animation;
}

