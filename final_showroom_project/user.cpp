#include "user.h"
#include "Register.h"
#include <ctime>

user::user() {

    srand(time(0));
    id = rand() % (10000 - 1000 - 1) + 1000;;
}
void user::get_information() {
    cout << "\n\t\t Your id is :" << id;
    cout << "\nEnter your name :  ";
    cin >> name;
    cout << "\n Enter password  :   ";
    cin >> password;
}
void user::search_about_car(int index_of_user) {
    cout<<"\n----------------------------------------------------\n";
    int id, action;
    bool found = false;
    Register r;
    show.get_cars_from_file();
    cout << "\n\t\tEnter car id :";
    cin >> id;
    for (int i = 0; i < show.ListOfCars.size(); i++) {
        if (id == show.ListOfCars[i].car_id) {
            cout << "\n\t Showroom id : " << show.ListOfCars[i].showroom_id;
            cout << "\n\t Car id :" << show.ListOfCars[i].car_id;
            cout << "\n\t Car make : " << show.ListOfCars[i].car_make;
            cout << "\n\t Car model : " << show.ListOfCars[i].car_model;
            cout << "\n\t Car price: " << show.ListOfCars[i].car_price;
            cout << "\n\t Car year : " << show.ListOfCars[i].car_year;
            found = true;
            cout << "\n\n\t\tPress 1 for new search and 2 for back to main menu ....";
            cout << "\n\tYour decision is : "; cin >> action;
            switch (action)
            {
            case 1:
                search_about_car(index_of_user);
                break;
            default:
                r.user_view(index_of_user);
                break;
            }
        }
    }
    if (found == false) {
        cout << "\n\t\tYou entered wrong id to enter id again press 1 to back main list press 2";
        cout << "\n\tYour decision is : "; cin >> action;
        switch (action)
        {
        case 1:
            search_about_car(index_of_user);
            break;
        default:
            r.user_view(index_of_user);
            break;
        }
    }
}
void user::search_about_garage(int index_of_user) {
    cout<<"\n----------------------------------------------------\n";
    int action;
    bool founded = false;
    Register r;
    admin1.get_garage_from_file();
    cout << "\n\t\t Enter garage id :";
    cin >> action;
    for (int i = 0; i < admin1.list_garages.size(); i++) {
        if (action == admin1.list_garages[i].garage_id) {
            founded = true;
            cout << "\n\t Garage Name : " << admin1.list_garages[i].garage_name;
            cout << "\n\t Garage Id : " << admin1.list_garages[i].garage_id;
            cout << "\n\t Garage Location : " << admin1.list_garages[i].garage_location;
            cout << "\n\t Garage Phone Number : " << admin1.list_garages[i].garage_phone;
            cout << "\n\n\t\tPress 1 for new search and 2 for back to main menu ....";
            cout << "\n\tYour decision is : "; cin >> action;
            switch (action)
            {
            case 1:
                search_about_garage(index_of_user);
                break;
            default:
                r.user_view(index_of_user);
                break;
            }
        }
    }
    if (founded == false) {
        cout << "\n\t\tYou entered wrong action to enter id again press 1 to back main list press 2";
        cout << "\n\tYour decision is : "; cin >> action;
        switch (action)
        {
        case 1:
            search_about_garage(index_of_user);
            break;
        default:
            r.user_view(index_of_user);
            break;
        }
    }
}
void user::search_about_service(int index_of_user) {
    int garage_id, service_id, action;
    bool garage_founded = false;
    bool service_founded = false;
    Register r;
    admin1.get_garage_from_file();
    cout<<"\n----------------------------------------------------\n";
    cout << "\n\t\t Enter garage id ";
    cin >> garage_id;

    for (int i = 0; i < admin1.list_garages.size(); i++) {
        if (garage_id == admin1.list_garages[i].garage_id) {
            garage_founded = true;
            break;
        }
    }

    if (garage_founded == true) {
        admin1.get_service_info();
        cout << "\n\t\t Enter service id :";
        cin >> service_id;
        for (int i = 0; i < admin1.list_services.size(); i++) {
            if (service_id == admin1.list_services[i].service_id && garage_id == admin1.list_services[i].service_garage_id) {// ?????? 3 ???? ???? ?????? , ??? ?? ?? ??????
                service_founded = true;
                cout << "\n\t Service Id : " << admin1.list_services[i].service_id;
                cout << "\n\t Service Name : " << admin1.list_services[i].service_name;
                cout << "\n\t Service Price :" << admin1.list_services[i].service_price;
                cout << "\n\n\t\tPress 1 for new search and 2 for back to main menu ....";
                cout << "\n\tYour decision is : "; cin >> action;
                switch (action)
                {
                case 1:
                    search_about_service(index_of_user);
                    break;
                default:
                    r.user_view(index_of_user);
                    break;
                }
            }

        }
        if (service_founded == false) {
            cout << "\n\t\tYou entered wrong service id";
        }

    }
    else if (garage_founded == false) {
        cout << "\n\t\tyou entered wrong garage id to search again press 1";
        cout << "\n\tYour decision is : "; cin >> action;
        switch (action)
        {
        case 1:search_about_service(index_of_user);
            break;
        default:r.user_view(index_of_user);
            break;
        }
    }
}

void user::search_about_showroom(int index_of_user) {
    cout<<"\n----------------------------------------------------\n";
    int id, action;
    bool found = false;
    Register r;
    admin1.get_rooms_from_file();
    cout << "\nEnter room id : ";
    cin >> id;
    for (int i = 0; i < admin1.list_showrooms.size(); i++) {
        if (id == admin1.list_showrooms[i].showrooms_id) {
            cout << "\n\t Room Id : " << admin1.list_showrooms[i].showrooms_id;
            cout << "\n\t Room Name : " << admin1.list_showrooms[i].showrooms_name;
            cout << "\n\t Room Phone : " << admin1.list_showrooms[i].showrooms_phone;
            cout << "\n\t Room Location : " << admin1.list_showrooms[i].showrooms_location;
            found = true;
            cout << "\n\n\t\tPress 1 for new search and 2 for back to main menu ....";
            cout << "\n\tYour decision is : "; cin >> action;
            switch (action)
            {
            case 1:
                search_about_showroom(index_of_user);
                break;
            default:
                r.user_view(index_of_user);
                break;
            }
        }
    }
    if (found == false) {
        cout << "\n\t\tYou entered wrong id to enter id again press 1 to back for main press 2";
        cout << "\n\tYour decision is : "; cin >> action;
        switch (action)
        {
        case 1:search_about_showroom(index_of_user);
            break;
        default:
            break;
        }
    }
}
void user::view_showrooms() {
    cout<<"\n----------------------------------------------------\n";
    int action;
    Register r;
    admin1.get_rooms_from_file();
    show.get_cars_from_file();

    for (int i = 0; i < admin1.list_showrooms.size(); i++) {
        cout << "\n\t Room Id : " << admin1.list_showrooms[i].showrooms_id;
        cout << "\n\t Room Name : " << admin1.list_showrooms[i].showrooms_name;
        cout << "\n\t Room Phone : " << admin1.list_showrooms[i].showrooms_phone;
        cout << "\n\t Room Location : " << admin1.list_showrooms[i].showrooms_location;
        cout << "\n\t #####################################################\n";
        for (int j = 0; j < show.ListOfCars.size(); ++j) {
            if ((admin1.list_showrooms[i].showrooms_id == show.ListOfCars[j].showroom_id) && (show.ListOfCars[j].rented == true)) {
                cout << "\n\t\t Car id :" << show.ListOfCars[j].car_id;
                cout << "\n\t\t Car make : " << show.ListOfCars[j].car_make;
                cout << "\n\t\t Car model : " << show.ListOfCars[j].car_model;
                cout << "\n\t\t Car price: " << show.ListOfCars[j].car_price;
                cout << "\n\t\t Car year : " << show.ListOfCars[j].car_year;
                cout << "\n------------------------------------------------------\n";
            }
        }
    }
    /* cout << "\n\n\t\tPress 1 for view again and 2 for back to main menu ....";
     cout << "\n\tYour decision is : " ; cin >> action;
     switch (action)
     {
         case 1:
             view_showrooms();
             break;
         default:
             r.user_view();
             break;
     }*/
}

void user::view_garage() {
    cout<<"\n----------------------------------------------------\n";
    int action;
    Register r;
    admin1.get_garage_from_file();
    admin1.get_service_info();
    for (int i = 0; i < admin1.list_garages.size(); i++) {
        cout << "\n\t Garage Name : " << admin1.list_garages[i].garage_name;
        cout << "\n\t Garage Id : " << admin1.list_garages[i].garage_id;
        cout << "\n\t Garage Location : " << admin1.list_garages[i].garage_location;
        cout << "\n\t Garage Phone Number : " << admin1.list_garages[i].garage_phone;
        cout << "\n\t #####################################################\n";
        for (int j = 0; j < admin1.list_services.size(); ++j) {
            if (admin1.list_garages[i].garage_id == admin1.list_services[j].service_garage_id) {
                cout << "\n\t\t Service Id : " << admin1.list_services[j].service_id;
                cout << "\n\t\t Service Name : " << admin1.list_services[j].service_name;
                cout << "\n\t\t Service Price :" << admin1.list_services[j].service_price;
                cout << "\n--------------------------------------------------------------\n";
            }
        }
    }
    /* cout << "\n\n\t\tPress 1 for view again and 2 for back to main menu ....";
     cout << "\n\tYour decision is : " ; cin >> action;
     switch (action)
     {
         case 1:
             view_garage();
             break;
         default:
             r.user_view();
             break;
     }*/
}
void user::get_buy_rent_file() {
    fstream file_out;
    file_out.open("buy_rent.text", ios::in);
    list_buy_rent.clear();
    string s;
    buy_rent temp;
    if (file_out.is_open()) {
        while (!file_out.eof()) {

            getline(file_out, s, ',');
            temp.buy_rent_id = atoi(s.c_str());//convert to int
            getline(file_out, s, ',');
            temp.customer_id = atoi(s.c_str());//convert to int
            getline(file_out, s, ',');
            temp.buy_rent_date = atoi(s.c_str());//convert to int
            getline(file_out, s, ',');
            temp.choosen_car.car_price = atof(s.c_str());//convert to int
            getline(file_out, s, ',');
            temp.choosen_car.car_id = atoi(s.c_str());
            getline(file_out, s, ',');
            temp.choosen_car.car_model = s;
            getline(file_out, s);
            temp.returned = atoi(s.c_str());//check if it returned or not 1,0

            list_buy_rent.push_back(temp);

        }
        list_buy_rent.pop_back();
        file_out.close();
    }

}
void user::set_buy_rent_file() {
    fstream file_out;
    file_out.clear();
    file_out.open("buy_rent.text", ios::out);
    if (file_out.is_open()) {
        for (int i = 0; i < list_buy_rent.size(); i++) {
            file_out << list_buy_rent[i].buy_rent_id << ','
                << list_buy_rent[i].customer_id << ','
                << list_buy_rent[i].buy_rent_date << ','
                << list_buy_rent[i].choosen_car.car_price << ','
                << list_buy_rent[i].choosen_car.car_id << ','
                << list_buy_rent[i].choosen_car.car_model << ','
                << list_buy_rent[i].returned << endl;

        }
        file_out.close();
    }
}
//bool user::search_about_car(int Cid,int x) {
//   
//    //show.get_cars_from_file();
//    for (int i = 0; i < show.ListOfCars.size(); i++) {
//        if (Cid == show.ListOfCars[i].car_id) {
//          
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//
//
//}
void user::buy_car(int index_of_user) {
    int Buy_id;
    buy_rent newBuy;
    bool flag = false;
    char action;
    Register r;
    cout<<"\n----------------------------------------------------\n";
    view_showrooms();
    cout << endl;
    cout << "\n\t\t Enter car id that you want to buy : ";
    cin >> Buy_id;
    cout << endl;
    for (int i = 0; i < show.ListOfCars.size(); i++) {
        if (Buy_id == show.ListOfCars[i].car_id) {
            cout << "\n\t\tFounded !!!" << endl;
            cout << "\t Are you sure to buy this car ? y/n " << endl;
            cout << "\t Your Decision is : "; cin >> action;
            switch (action)
            {
            case 'y': {
                flag = true;
            }
                    break;
            default: {
                cout<<"\n----------------------------------------------------\n";
                buy_car(index_of_user);
            }break;
            }

        }

    }
    if (flag == true)
    {
        get_buy_rent_file();
        r.get_users_from_file();
        cout<<"\n----------------------------------------------------\n";
        /* cout << "\n\t\t>>> For your safety , Please enter your details again !! <<< " ;
         cout << endl;
         userId = r.signin2();*/
        newBuy.customer_id = r.users_list[index_of_user].id;
        newBuy.buy_rent_date = time(0);
        newBuy.choosen_car.car_id = Buy_id;
        for (int i = 0; i < show.ListOfCars.size(); i++) {
            if (Buy_id == show.ListOfCars[i].car_id) {
                newBuy.choosen_car.car_price = show.ListOfCars[i].car_price;
                newBuy.choosen_car.car_model = show.ListOfCars[i].car_model;
                show.ListOfCars.erase(show.ListOfCars.begin() + i);
                show.set_cars_to_file();
                break;
            }
        }
        list_buy_rent.push_back(newBuy);

        cout << "\n\t\tBuy successfully" << endl;
        set_buy_rent_file();
    }
    else {
        cout << "\n\t\tWrong id!!!" << endl;
    }

}

void user::rent_car(int index_of_user) {

    int Rent_id;
    buy_rent newRent;
    bool flag = false;
    char action;
    Register r;
    r.get_users_from_file();
    cout<<"\n----------------------------------------------------\n";
    view_showrooms();
    cout << endl;
    cout << "\n\t\t Enter car id that you want to rent : ";
    cin >> Rent_id;
    cout << endl;
    for (int i = 0; i < show.ListOfCars.size(); i++) {
        if (Rent_id == show.ListOfCars[i].car_id) {
            cout << "\n\t\tFounded !!!" << endl;
            cout << "\t Are you sure to rent this car ? y/n " << endl;
            cout << "\t Your decision is : "; cin >> action;
            switch (action)
            {
            case 'y': {
                flag = true;
            }
                    break;
            default: {
                cout<<"\n----------------------------------------------------\n";
                rent_car(index_of_user);
            }break;
            }

        }

    }
    if (flag == true)
    {
        get_buy_rent_file();
        cout<<"\n----------------------------------------------------\n";
        /* cout << "\n\t\t >>> for your safety : Please enter your details again !! <<< ";
         cout << endl;
         userId = r.signin2();*/
        int minutes;
        newRent.customer_id = r.users_list[index_of_user].id;
        cout << "\n\nEnter minutes you want to rent :: ";
        cin >> minutes;
        newRent.buy_rent_date = time(0) + (minutes * 60);//end of renting time
        newRent.choosen_car.car_id = Rent_id;
        for (int i = 0; i < show.ListOfCars.size(); i++) {
            if (Rent_id == show.ListOfCars[i].car_id) {
                newRent.choosen_car.car_price = show.ListOfCars[i].car_price;
                newRent.choosen_car.car_model = show.ListOfCars[i].car_model;
                show.ListOfCars[i].rented = false;
                show.ListOfCars[i].returned_time = newRent.buy_rent_date;
                //show.ListOfCars.erase(show.ListOfCars.begin() + i);
                show.set_cars_to_file();
                break;
            }
        }


        list_buy_rent.push_back(newRent);

        cout << "\n\t\tRent successfully" << endl;
        set_buy_rent_file();
    }
    else {
        cout << "\n\t\tWrong id!!!" << endl;
    }
}
void user::get_service_process_file() {
    fstream file_out;
    file_out.open("service_process.text", ios::in);
    list_service_process.clear();
    string s;
    service_process temp;
    if (file_out.is_open()) {
        while (!file_out.eof()) {
            getline(file_out, s, ',');
            temp.process_id = atoi(s.c_str());
            getline(file_out, s, ',');
            temp.customer_id = atoi(s.c_str());
            getline(file_out, s, ',');
            temp.service_user.service_id = atoi(s.c_str());
            getline(file_out, s, ',');
            temp.service_user.service_name = s;
            getline(file_out, s, ',');
            temp.service_user.service_price = s;
            getline(file_out, s);
            temp.date = atoi(s.c_str());

            list_service_process.push_back(temp);

        }
        list_service_process.pop_back();
        file_out.close();
    }
}
void user::set_service_process_file() {
    fstream file_out;
    file_out.clear();
    file_out.open("service_process.text", ios::out);
    if (file_out.is_open()) {
        for (int i = 0; i < list_service_process.size(); i++) {
            file_out << list_service_process[i].process_id << ',' << list_service_process[i].customer_id << ','
                << list_service_process[i].service_user.service_id << ','
                << list_service_process[i].service_user.service_name << ','
                << list_service_process[i].service_user.service_price << ','
                << list_service_process[i].date << endl;
        }
        file_out.close();
    }
}

//void user::use_service(int index_of_user) {
//    cout<<"\n----------------------------------------------------\n";
//    int service_id, garage_id;
//    int customerID, decision;
//    Register r;
//    string service_name, service_price;
//    service_process new_service_process;
//    bool flag1 = false, flag2 = false;
//    char action;
//    view_garage();
//    cout << "\n\n\t\tEnter garage id : " << endl;
//    cin >> garage_id;
//    admin1.get_garage_from_file();
//    admin1.get_service_info();
//    for (int i = 0; i < admin1.list_garages.size(); i++) {
//        if (garage_id == admin1.list_garages[i].garage_id) {
//            for (int j = 0; j < admin1.list_services.size(); ++j) {
//                if (garage_id == admin1.list_services[j].service_garage_id) {
//                    cout << "\n\t Service Id : " << admin1.list_services[j].service_id;
//                    cout << "\n\t Service Name : " << admin1.list_services[j].service_name;
//                    cout << "\n\t Service Price :" << admin1.list_services[j].service_price;
//                    cout << "\n------------------------------------------------------\n";
//                    flag1 = true;
//                }
//            }
//        }
//    }
//    if (flag1 == true) {
//        cout << "\n\t\tEnter Service id : ";
//        cin >> service_id;
//        for (int i = 0; i < admin1.list_services.size(); i++) {
//            if (service_id == admin1.list_services[i].service_id && garage_id == admin1.list_services[i].service_garage_id) {
//                cout << "\n\t\tFounded !!!" << endl;
//                service_name = admin1.list_services[i].service_name;
//                service_price = admin1.list_services[i].service_price;
//                cout << "\t Are you sure to use this service ? y/n " << endl;
//                cout << "\t Your decision is : "; cin >> action;
//                switch (action)
//                {
//                case 'y': {
//                    flag2 = true;
//                }
//                        break;
//                default: {
//                    cout<<"\n----------------------------------------------------\n";
//                    use_service(index_of_user);
//                }break;
//                }
//
//            }
//
//        }
//    }
//    if (flag2 == true) {
//        get_service_process_file();
//        r.get_users_from_file();
//        cout<<"\n----------------------------------------------------\n";
//        /*  cout << "\n\t\t >>> for your safety , please enter your details again !! <<< ";
//          customerID = r.signin2();*/
//
//        new_service_process.customer_id = r.users_list[index_of_user].id;
//
//        new_service_process.service_user.service_id = service_id;
//
//        new_service_process.service_user.service_name = service_name;
//
//        new_service_process.service_user.service_price = service_price;
//
//        new_service_process.date = time(0);
//
//        list_service_process.push_back(new_service_process);
//        cout << "\n\t\tService added successfully" << endl;
//        set_service_process_file();
//        cout << "\n\t\tPress 1 to return to main menu or 2 to exit ...";
//        cout << "\n\t Your decision is : "; cin >> decision;
//        switch (decision) {
//        case 1: r.user_view(index_of_user);
//            break;
//        default:
//            _Exit(10);
//            break;
//        }
//    }
//    else {
//        cout << "\n\t\tWrong id !!" << endl;
//        use_service(index_of_user);
//    }
//
//}

void user::use_service(int index_of_user) {
    //cout<<"\n----------------------------------------------------\n";
    int service_id, garage_id;
    int customerID, decision;
    Register r;
    string service_name, service_price;
    service_process new_service_process;
    bool flag1 = false, flag2 = false;
    char action;
    int count = 0;
    view_garage();
    cout << "\n\n\t\tEnter garage id : " << endl;
    cin >> garage_id;

    admin1.get_garage_from_file();
    admin1.get_service_info();
    for (int i = 0; i < admin1.list_garages.size(); i++) {
        if (garage_id == admin1.list_garages[i].garage_id) {

            for (int j = 0; j < admin1.list_services.size(); ++j) {
                if (garage_id == admin1.list_services[j].service_garage_id) {
                    cout << "\n\t Service Id : " << admin1.list_services[j].service_id;
                    cout << "\n\t Service Name : " << admin1.list_services[j].service_name;
                    cout << "\n\t Service Price :" << admin1.list_services[j].service_price;
                    cout << "\n------------------------------------------------------\n";
                    flag1 = true;
                }
                else {

                    cout << "\n\t There's no services there \n";
                    int x;

                    cout << " 1. back to add service" << endl;
                    cout << " 2. back to menu" << endl;
                    cin >> x;
                    if (x == 1) {
                        use_service(index_of_user);
                    }
                    else
                        r.user_view(index_of_user);

                }
            }
        }
    }
    if (flag1 == true) {
        cout << "\n\t\tEnter Service id : ";
        cin >> service_id;
        for (int i = 0; i < admin1.list_services.size(); i++) {
            if (service_id == admin1.list_services[i].service_id && garage_id == admin1.list_services[i].service_garage_id) {
                cout << "\n\t\tfounded !!!" << endl;
                service_name = admin1.list_services[i].service_name;
                service_price = admin1.list_services[i].service_price;
                cout << "\t Are you sure to use this service ? y/n " << endl;
                cout << "\t Your decision is : "; cin >> action;
                switch (action)
                {
                case 'y': {
                    flag2 = true;
                    break;
                }

                default: {
                    cout<<"\n----------------------------------------------------\n";
                    use_service(index_of_user);
                    break;
                }
                }

            }
            if (flag2 == true)
                break;
        }
    }
    if (flag2 == true) {
        get_service_process_file();
        r.get_users_from_file();
        cout<<"\n----------------------------------------------------\n";
        /*  cout << "\n\t\t >>> for your safety , please enter your details again !! <<< ";
          customerID = r.signin2();*/

        new_service_process.customer_id = r.users_list[index_of_user].id;

        new_service_process.service_user.service_id = service_id;

        new_service_process.service_user.service_name = service_name;

        new_service_process.service_user.service_price = service_price;

        new_service_process.date = time(0);

        list_service_process.push_back(new_service_process);
        cout << "\n\t\tservice added successfully" << endl;
        set_service_process_file();
        cout << "\n\t\tpress 1 to return to main menu or 2 to exit ...";
        cout << "\n\t Your decision is : "; cin >> decision;
        switch (decision) {
        case 1: r.user_view(index_of_user);
            break;
        default:
            exit;
            break;
        }
    }
    else {
        int x;
        cout << "WRONG ID!!!!!!!" << endl;
        cout << " 1. back to add service" << endl;
        cout << " 2. back to menu" << endl;
        cin >> x;
        if (x == 1) {
            use_service(index_of_user);
        }
        else
            r.user_view(index_of_user);
    }

}
void user::history(int index_of_user) {
    Register r;
    int decision;
    get_buy_rent_file();
    get_service_process_file();
    r.get_users_from_file();
    cout<<"\n----------------------------------------------------\n";
    /*cout << "\n\t\t >>> for your safety , please enter your details again !! <<< ";
    user_id = r.signin2();*/
#pragma warning( disable : 4996  )
    for (int i = 0; i < list_buy_rent.size(); i++) {
        if (r.users_list[index_of_user].id == list_buy_rent[i].customer_id) {
            cout << "\n\t\tCar name : " << list_buy_rent[i].choosen_car.car_model << endl;
            cout << "\t\tCar price : " << list_buy_rent[i].choosen_car.car_price << endl;
            tm* tm_local = localtime(&list_buy_rent[i].buy_rent_date);//print local time 
            cout << "\t\tDate : " << tm_local->tm_year + 1900 << '\\' << tm_local->tm_mon + 1
            << "\\" << tm_local->tm_mday << "\t\t" << tm_local->tm_hour << ":" << tm_local->tm_min << endl;
            cout << "\t\tId process : " << list_buy_rent[i].buy_rent_id << endl;
            cout << "--------------------------------------------------------" << endl;
        }
    }
#pragma warning( disable : 4996  )
    cout << "\t\t\t<<<< All services >>>> \n\n";
    for (int i = 0; i < list_service_process.size(); i++) {
        if (r.users_list[index_of_user].id == list_service_process[i].customer_id) {
            cout << "Service name : " << list_service_process[i].service_user.service_name << endl;
            cout << "Service price : " << list_service_process[i].service_user.service_price << endl;
            tm* tm_local = localtime(&list_service_process[i].date);//print local time 
            cout << "Date : " << tm_local->tm_year + 1900 << '\\' << tm_local->tm_mon + 1
            << "\\" << tm_local->tm_mday << "\\" << tm_local->tm_hour << "\\" << tm_local->tm_min << endl;
            cout << "Id process : " << list_service_process[i].service_user.service_id << endl;
            cout << "---------------------------------------------" << endl;
        }
    }
    cout << "press 1 to return to main menu or 2 to exit .. ";
    cout << "Your decision is : "; cin >> decision;
    switch (decision) {
    case 1: r.user_view(index_of_user);
        break;
    default:
        exit;
        break;
    }
}
