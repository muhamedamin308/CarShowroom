#include "service_process.h"
service_process::service_process() {


	srand(time(0));
	process_id = rand() % (10000 - 1000 - 1) + 1000;

}
