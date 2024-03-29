/* test.c --- 
 * 
 * 
 * Author: YENKAI HUANG, HONGKE (LUIS) LU, ERIN
 * Created: Tue Jan 24 08:33:13 2023 (-0500)
 * Version: 1.0 
 * 
 * Description: test file for car
 * 
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "list.h"

//functions for lapply()
void print_car_current(car_t *cp){
	printf("car current = %p\n", (void*)cp); 
}

void print_car_next(car_t *cp){
	printf("car next = %p\n",(void*) cp->next);
}

void print_car_price(car_t *cp){
	printf("car price = %lf\n", cp->price);
}

void print_car_plate(car_t *cp){
	printf("car plate = %s\n", cp->plate);
}


//create car object
car_t *make_car(char *plateP, double price, int year){

	car_t *car;

	if( !(car = (car_t*)malloc(sizeof(car_t))) ){
		printf("Error:malloc failed allocating car!!!!\n");
		return NULL;
	}
	car -> next = NULL;
	strcpy(car->plate, plateP);
	car -> price = price;
	car -> year = year;
	
	return car;
}


int main(void){

	void (*fn_ptr1)(car_t *cp) = print_car_plate;
	void (*fn_ptr2)(car_t *cp) = print_car_price;
	void (*fn_ptr3)(car_t *cp) = print_car_next;

	car_t *car1 = make_car("ABC1234", 3000.0, 2003);
	car_t *car2 = make_car("ABC1235", 2000.0, 2015);
	car_t *car3 = make_car("ABC1236", 1000.0, 1998);

	lput(car1);
	lput(car2);
	lput(car3);

	lapply(fn_ptr1);
	lapply(fn_ptr2);
	lapply(fn_ptr3);

	free(car1);
	free(car2);
	free(car3);
	
	exit(EXIT_SUCCESS);
}


