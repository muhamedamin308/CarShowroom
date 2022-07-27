#include "service.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include<ctime>
#include <iostream>
service::service() {
	srand(time(0));
	service_id = rand() % (10000 - 1000 - 1) + 1000;
}
void service::set_service_information() {
	fstream file_service;
	file_service.open("service.text", ios::out);

	cout << "\nyou are goning to add new service" << endl;

	cout << "Enter service  name : ";
	cin >> service_name;
	cout << "Enter service price : ";
	cin >> service_price;

	cout << "added successfully ";

}




