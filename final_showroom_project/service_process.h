#pragma once
#include <string>
#include <vector>
#include<ctime>
#include"service.h"
using namespace std;
class service_process
{
public:
	int process_id;
	int customer_id;
	time_t date;
	service service_user;

public:

	service_process();

};

