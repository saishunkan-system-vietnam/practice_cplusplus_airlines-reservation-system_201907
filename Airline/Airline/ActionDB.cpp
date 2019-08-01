#include "ActionDB.h"


MYSQL* ActionDB::getConnect()
{
	return DBConnectSupport::GetInstance()->getConnnect();
}

void ActionDB::execute(string sql)
{
	string insert_query = sql;

	const char* q = insert_query.c_str(); // c_str converts string to constant char and this is required

	qstate = mysql_query(this->getConnect(), q);

	if (!qstate)
	{
		cout << endl << "Successfully execute in database." << endl;
		//closeConnect();
	}
	else
	{
		cout << "Execute error";
	}
}

MYSQL_RES* ActionDB::select(string sql)
{
	string query = sql;
	const char* q = query.c_str();
	qstate = mysql_query(this->getConnect(), q);

	cout << endl;
	//cout << title << endl;
	if (!qstate)
	{
		res = mysql_store_result(this->getConnect());
		return res;
	}
	else
	{
		cout << "Query Execution Problem!" << mysql_errno(this->getConnect()) << endl;
	}
}
