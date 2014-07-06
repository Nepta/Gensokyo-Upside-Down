#ifndef __Animated_H__
#define __Animated_H__

#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite{
	unsigned int currentAnimation_;
	std::vector<sf::IntRect> animationList_;

public:
	AnimatedSprite(sf::Texture &texture);
	void addAnimation(sf::IntRect animation);
	void nextAnimation();
};

#endif /* __Sprite_H__ */

