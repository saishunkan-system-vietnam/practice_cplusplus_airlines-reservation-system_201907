#pragma once
#include "DBConnectUtil.h"

template<class T>
class DBConnectSupport: public DBConnectUtil<T>
{
private:
	static DBConnectSupport* instance;

	DBConnectSupport() = default;

	~DBConnectSupport() = default;

public:
	static DBConnectSupport* GetInstance();
};

