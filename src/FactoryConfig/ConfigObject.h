#ifndef __ConfigObject_H__
#define __ConfigObject_H__

#include "../Animation.h"

class ConfigObject{
	std::string configName_;
	std::string spriteSheetName_;

public:
	ConfigObject() = default;
	ConfigObject(std::string configName, std::string spriteSheetName);
	virtual std::string configName();
	virtual std::string spriteSheetName();
	virtual Animation::HashMap config();
};

#endif /* __ConfigObject_H__ */

