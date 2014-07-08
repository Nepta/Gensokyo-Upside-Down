#include "MoveAction.h"
#include <SFML/Graphics.hpp>

MoveAction::MoveAction(sf::Sprite& sprite) : SpriteAction(sprite){}

MoveAction* MoveAction::setDirection(MoveAction::Direction direction){
	direction_ = direction;
	return this;
}

void MoveAction::execute(){
	sf::Vector2f position = sprite().getPosition();
	switch(direction_){
		case MoveAction::UP:
			position.y--;
			break;
		case MoveAction::RIGHT:
			position.x++;
			break;
		case MoveAction::DOWN:
			position.y++;
			break;
		case MoveAction::LEFT:
			position.x--;
			break;
		case MoveAction::UNKNOWN:
		default: break;
	}
	sprite().setPosition(position);
}

