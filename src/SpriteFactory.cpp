#include <SFML/Graphics.hpp>
#include "SpriteFactory.h"

SpriteFactory::SpriteFactory(std::string path) : path_(path){}

AnimatedSprite SpriteFactory::create(std::string spriteName){
	auto config = configList_[spriteName];
	sf::Texture& spriteSheet = textureList_[spriteName];
	AnimatedSprite sprite(spriteSheet, config);
	return sprite;
}

void SpriteFactory::addAnimation(std::string animationName, Animation& animation){
	animationList_[animationName] = animation;
}

void SpriteFactory::addConfig(std::string configName, std::string spriteSheetName, std::initializer_list<Animation::HashMap::value_type> animationConf){
	addSpriteSheet(spriteSheetName);
	configList_[configName] = animationConf;
}

void SpriteFactory::addSpriteSheet(std::string spriteSheetName){
	sf::Texture spriteSheet;
	spriteSheet.loadFromFile(path_ + "/" + spriteSheetName);
	textureList_[spriteSheetName] = spriteSheet;
}

