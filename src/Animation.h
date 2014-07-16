#ifndef __Animation_H__
#define __Animation_H__

#include <SFML/Graphics.hpp>

class Animation{
	unsigned int currentAnimation_ = 0;
	std::vector<sf::IntRect> frameList_;

public:
	void addFrame(sf::IntRect frame);
	sf::IntRect& next();
	sf::IntRect& currentAnimation();
};

#endif /* __Animation_H__ */

