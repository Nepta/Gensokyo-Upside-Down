#ifndef __SpriteFactory_H__
#define __SpriteFactory_H__

#include "AnimatedSprite.h"
#include "Animation.h"

class SpriteFactory{
	std::string path_;
	Animation::HashMap animationList_;
	std::unordered_map<std::string, sf::Texture> textureList_;
	std::unordered_map<std::string, Animation::HashMap> configList_;

private:
	void addSpriteSheet(std::string configName, std::string spriteSheetName);
	
public:
	SpriteFactory(std::string path = "");
	AnimatedSprite create(std::string spriteName);
	void addConfig(std::string animationName, std::string configName, std::initializer_list<Animation::HashMap::value_type>);
};

#endif /* __SpriteFactory_H__ */

