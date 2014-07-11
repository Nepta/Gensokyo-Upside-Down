#ifndef __MoveAction_H__
#define __MoveAction_H__

#include "AnimatedSpriteAction.h" 

class MoveAction : public AnimatedSpriteAction{
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
	MoveAction(AnimatedSprite& sprite);
	MoveAction* setDirection(Direction direction);
	void execute();
};

#endif /* __MoveAction_H__ */

