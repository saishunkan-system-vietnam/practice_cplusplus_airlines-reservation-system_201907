#include "DBConnectSupport.h"

DBConnectSupport* DBConnectSupport::instance = nullptr;


DBConnectSupport* DBConnectSupport::GetInstance()
{
	if (!instance) {
		instance = new DBConnectSupport;
	}
	return instance;
}
