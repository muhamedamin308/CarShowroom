#pragma once
#include <string>
#include <vector>
#include"car.h"
#include<ctime>
using namespace std;
class buy_rent

{
public:

	int buy_rent_id;
	int customer_id;
	time_t buy_rent_date;
	car choosen_car;
	bool returned;
public:

	buy_rent();


};

