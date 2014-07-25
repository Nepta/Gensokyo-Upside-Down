#include <SFML/Graphics.hpp>
#include "SpriteFactory.h"

SpriteFactory::SpriteFactory(std::string path) : path_(path){}

AnimatedSprite SpriteFactory::create(std::string spriteName){
	auto config = configList_[spriteName];
	sf::Texture& spriteSheet = textureList_[spriteName];
	AnimatedSprite sprite(spriteSheet, config);
	return sprite;
}

void SpriteFactory::addSpriteSheet(std::string configName, std::string spriteSheetName){
	sf::Texture spriteSheet;
	spriteSheet.loadFromFile(path_ + "/" + spriteSheetName);
	textureList_[configName] = spriteSheet;
}

void SpriteFactory::addConfig(std::string configName, std::string spriteSheetName, Animation::HashMap animationConf){
	addSpriteSheet(configName,spriteSheetName);
	configList_[configName] = animationConf;
}

void SpriteFactory::addConfig(ConfigObject& object){
	addConfig(object.configName(), object.spriteSheetName(), object.config());
}

