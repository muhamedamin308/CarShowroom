#include "car.h"
#include <cstdlib>
#include<ctime>

car::car() {

	srand(time(0));
	car_id = rand();
	rented = true;
	returned_time = time(0) - 60;

}
void car::set_car_information(int showrooms_id) {

	showroom_id = showrooms_id;
	cout << "\n\tcar id is :" << car_id;
	cin.ignore();
	cout << "\nEnter car make :";
	getline(cin, car_make);
	cout << "\nEnter car model :";
	getline(cin, car_model);
	cout << "\n enter car price :";
	cin >> car_price;
	cout << "\nenter car year :";
	cin >> car_year;

}
