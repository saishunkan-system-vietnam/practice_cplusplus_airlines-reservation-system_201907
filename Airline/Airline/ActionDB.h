#pragma once
#include "DBConnectSupport.h"

template<class T>
class ActionDB
{
private:
	DBConnectSupport<T>* dbptr = DBConnectSupport<T>::GetInstance();
public:
	
	//void execute(string sql);

};

