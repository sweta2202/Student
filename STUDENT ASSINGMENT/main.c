
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <assert.h>


int main(int argc, char *argv[]) {
	int choice;
	int accept;
	Student stu[TOTAL_STUDENT];
	accept=declaration();
	assert(accept==1);
	do{
	    printf("\nCHOOSE FROM ABOVE OPTIONS:\n");
	    scanf("%d",&choice);
	    switch(choice){

	    	case 1: manage_seats();
			break;

			case 2:	student_reg(stu);
		    break;

			case 3: display_total_filled_seats();
			break;

			case 4: display(stu);
			break;

			case 5: display_waiting_students(stu);
			break;

			case 6: waiting_students(stu);
			break;

			default: assert(choice<7);

			}


	}while(choice!=0);

	return 0;
}
