#ifndef __MoveAction_H__
#define __MoveAction_H__

#include "SpriteAction.h" 

class MoveAction : public SpriteAction{
public:
	enum Direction{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		UNKNOWN
	};

private:
	Direction direction_ = UNKNOWN;
public:
	MoveAction(sf::Sprite& sprite);
	MoveAction* setDirection(Direction direction);
	void execute();
};

#endif /* __MoveAction_H__ */

