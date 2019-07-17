#pragma once
#include "DBConnectSupport.h"

class ActionDB
{
private:
	DBConnectSupport* dbptr = DBConnectSupport::GetInstance();
public:
	
	void execute(string sql);

};

