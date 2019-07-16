#pragma once
class DBConnectSupport
{
private:
	static DBConnectSupport* instance;

	DBConnectSupport() = default;

	~DBConnectSupport() = default;

public:
	static DBConnectSupport* GetInstance();
};

