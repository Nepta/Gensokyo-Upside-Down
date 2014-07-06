#include "EventManager.h"

using namespace sf;

void EventManager::addEvent(Event event){
	if(event.type == Event::KeyPressed){
		switch(event.key.code){
			case Keyboard::Key::Z:
				eventList_["up"] = std::move(event);
				break;
			case Keyboard::Key::Q:
				eventList_["left"] = std::move(event);
				break;
			case Keyboard::Key::S:
				eventList_["down"] = std::move(event);
				break;
			case Keyboard::Key::D:
				eventList_["right"] = std::move(event);
				break;
			default:break;
		}
	}
}

bool EventManager::have(std::string event){
	return eventList_.count(event) > 0;
}

void EventManager::flushEvent(){
	eventList_.clear();
}

