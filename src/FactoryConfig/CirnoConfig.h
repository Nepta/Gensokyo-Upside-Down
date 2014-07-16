#ifndef __CirnoConfig_H__
#define __CirnoConfig_H__

#include "ConfigObject.h"

class CirnoConfig : public ConfigObject{
public:
	CirnoConfig() : ConfigObject("cirno", "cirno.png"){};
};

#endif /* __CirnoConfig_H__ */

