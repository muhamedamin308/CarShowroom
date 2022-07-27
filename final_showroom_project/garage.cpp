#include "garage.h"

garage::garage() {
	srand(time(0));
	garage_id = rand() % (10000 - 1000 - 1) + 1000;
}

void garage::set_garage_information()
{
	system("cls");
	cout << "\nyou are going to add new garage";
	cout << "\n\tgarage id is :" << garage_id;
	cin.ignore();
	cout << "\nEnter garage name : ";

	getline(cin, garage_name);
	cout << "\nEnter garage location : ";

	getline(cin, garage_location);

	cout << "\nEnter garage phone number : ";
	getline(cin, garage_phone);

}


