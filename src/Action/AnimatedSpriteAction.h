#ifndef __AnimatedSpriteAction_H__
#define __AnimatedSpriteAction_H__

#include "SpriteAction.h"
#include "../AnimatedSprite.h"

class AnimatedSpriteAction : public SpriteAction{

public:
	AnimatedSpriteAction(AnimatedSprite& sprite);
	AnimatedSprite& sprite();
};

#endif /* __AnimatedSpriteAction_H__ */

