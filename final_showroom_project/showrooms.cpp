#include "showrooms.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include<ctime>
showrooms::showrooms() {
	srand(time(0));
	showrooms_id = rand() % (10000 - 1000 - 1) + 1000;
}

void showrooms::set_room_informatin() {
	cout<<"\n----------------------------------------------------\n";
	cout << "\nyou are goning to add new room";
	cin.ignore();
	cout << "\n\t room id is :" << showrooms_id;
	cout << "\nEnter showroom name : ";

	getline(cin, showrooms_name);
	cout << "\nEnter showroom location : ";

	getline(cin, showrooms_location);

	cout << "\nEnter showroom phone number : ";
	getline(cin, showrooms_phone);


}
void showrooms::get_cars_from_file() {
	ListOfCars.clear();
	fstream file_out;
	//int index = 0;
	string s;
	car temp;
	file_out.open("cars.text", ios::in);
	while (!file_out.eof()) {


		getline(file_out, s, ',');
		temp.showroom_id = atoi(s.c_str());//convert to int
		getline(file_out, s, ',');
		temp.car_id = atoi(s.c_str());//convert to int
		getline(file_out, s, ',');
		temp.car_make = s;
		getline(file_out, s, ',');
		temp.car_model = s;
		getline(file_out, s, ',');
		temp.car_price = atof(s.c_str());//convert to double
		getline(file_out, s, ',');
		temp.car_year = atoi(s.c_str());//convert to int
		getline(file_out, s, ',');
		temp.rented = atoi(s.c_str());//convert to int
		getline(file_out, s);
		temp.returned_time = atoi(s.c_str());//convert to int
		if (temp.returned_time < time(0)) {
			temp.rented = true;
		}
		ListOfCars.push_back(temp);
	}
	ListOfCars.pop_back();
	file_out.close();

}

void showrooms::add_car() {
	cout<<"\n----------------------------------------------------\n";
	get_cars_from_file();
	//cout<<"\n----------------------------------------------------\n";
	cout << "\n>>>you are going to add car to show room :: " << showrooms_name;
	car new_car;//new opject
	new_car.set_car_information(showrooms_id);//set its information and send id of show room
	ListOfCars.push_back(new_car);
	set_cars_to_file();

}

void showrooms::set_cars_to_file() {
	fstream file_out;
	file_out.clear();

	file_out.open("cars.text", ios::out);
	for (int i = 0; i < ListOfCars.size(); i++) {
		file_out << ListOfCars[i].showroom_id << ',' << ListOfCars[i].car_id << ',' << ListOfCars[i].car_make << ',' << ListOfCars[i].car_model << ',' << ListOfCars[i].car_price << ',' << ListOfCars[i].car_year << ',' << ListOfCars[i].rented << ',' << ListOfCars[i].returned_time << endl;
	}
	file_out.close();
}


void showrooms::update_car() {
	int id;
	bool found = false;
	get_cars_from_file();
	cout << "\n\t room id" << "\t car id " << "\tcar make " << "\tcar model" << "\tcar price " << "\tcar year\n\n";
	for (int i = 0; i < ListOfCars.size(); i++) {
		cout << "\t" << ListOfCars[i].showroom_id << "\t|\t" << ListOfCars[i].car_id << "\t|\t" << ListOfCars[i].car_make << "\t|\t" << ListOfCars[i].car_model << "\t|\t" << ListOfCars[i].car_price << "\t|\t" << ListOfCars[i].car_year << "\n";
	}
	cout << "\nEnter car id :";
	cin >> id;
	for (int i = 0; i < ListOfCars.size() - 1; i++) {
		if (id == ListOfCars[i].car_id) {
			cout << ListOfCars[i].car_id << "  " << ListOfCars[i].car_make << "  " << ListOfCars[i].car_model << "  " << ListOfCars[i].car_price << "  " << ListOfCars[i].car_year << endl;
			cout << "\n>>>you are going to modify record of  last car<<<";
			cout << "\nEnter new car  :showroom id :";
			cin >> ListOfCars[i].showroom_id;
			cout << "\nEnter new car id :";
			cin >> ListOfCars[i].car_id;
			cout << "\b\nEnter new car make :";
			cin >> ListOfCars[i].car_make;
			cout << "Enter new car model :";
			cin >> ListOfCars[i].car_model;
			cout << "Enter new car price:";
			cin >> ListOfCars[i].car_price;
			cout << "Enter new car year :";
			cin >> ListOfCars[i].car_year;
			found = true;
		}
	}
	if (found == false) {
		cout << "\nyou entered wrong id to enter id again press 1 to back main list press 2";
		cin >> id;
		switch (id)
		{
		case 1:
			update_car();
			break;

		default:
			break;
		}

	}
	set_cars_to_file();

}