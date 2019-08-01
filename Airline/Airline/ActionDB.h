#pragma once
#include "DBConnectSupport.h"

class ActionDB
{

public:

	int qstate;

	MYSQL_RES* res;
	
	MYSQL* getConnect();

	void execute(string sql);

	MYSQL_RES* select(string sql);

};

