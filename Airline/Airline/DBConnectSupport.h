#pragma once
#include "DBConnectUtil.h"


class DBConnectSupport: public DBConnectUtil
{
private:
	static DBConnectSupport* instance;

	DBConnectSupport() = default;

	~DBConnectSupport() = default;

public:
	static DBConnectSupport* GetInstance();
};

