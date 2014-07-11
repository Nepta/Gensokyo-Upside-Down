#include "Animation.h"

using namespace sf;

void Animation::addAnimation(IntRect animation){
	animationList_.push_back(animation);
}

IntRect& Animation::next(){
	currentAnimation_ = currentAnimation_+1 < animationList_.size() ? currentAnimation_+1 : 0;
	return currentAnimation();
}

IntRect& Animation::currentAnimation(){
	return animationList_[currentAnimation_];
}
