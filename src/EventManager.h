#ifndef __EventManager_H__
#define __EventManager_H__

#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

class EventManager{
public:
	std::unordered_map<std::string, bool> eventList_;

	void addEvent(sf::Event event);
	bool have(std::string);
	void flushEvent();
};

#endif /* __EventStack_H__ */

