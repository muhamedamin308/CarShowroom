#pragma once
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class car
{
public:
	int showroom_id;
	int car_id;
	string car_make;
	string car_model;
	double car_price;
	int car_year;
	bool rented;
	time_t returned_time;
	//string car_instalment;
public:

	car();
	void set_car_information(int showrooms_id);

};

