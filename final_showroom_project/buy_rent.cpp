#include "buy_rent.h"
#include "car.h"

buy_rent::buy_rent() {
	srand(time(0));
	buy_rent_id = rand() % (10000 - 1000 - 1) + 1000;
	returned = false;

}
