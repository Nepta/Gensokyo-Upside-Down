#ifndef __Animated_H__
#define __Animated_H__

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>
#include "Animation.h"

class AnimatedSprite : public sf::Sprite{
	std::string currentAnimation_;
	std::unordered_map<std::string, Animation> animationList_;

private:
	sf::IntRect& currentAnimation();

public:
	AnimatedSprite(sf::Texture &texture);
	void addAnimation(std::string animationName, Animation& animation);
	void nextAnimation();
	void setAnimation(std::string);
};

#endif /* __Sprite_H__ */

