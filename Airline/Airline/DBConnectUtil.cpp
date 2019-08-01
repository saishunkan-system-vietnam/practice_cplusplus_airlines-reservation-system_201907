#include "DBConnectUtil.h"

DBConnectUtil::DBConnectUtil()
{
	init();
}


MYSQL* DBConnectUtil::getConnnect()
{
	return this->conn;
}


void DBConnectUtil::closeConnect()
{
	mysql_close(this->conn);
}


void DBConnectUtil::init()
{
	ConnectProperties property;
	this->conn = mysql_init(0);
	this->conn = mysql_real_connect(conn, property.HOST, property.USER_NAME, property.PASSWORD, property.DB_NAME, property.PORT, NULL, 0);
	if (!conn) {
		std::cout << "Error connect";
		exit(1);
	}
}