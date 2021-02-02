
#include <string.h>
#include "functions.h"
#include <assert.h>
#include <stdio.h>

void manage_seats(){
	Program pog=program_seats();
	display_seats(pog);
}
Program program_seats(){
	Program pg;
	printf("\nENTER BDA SEATS:\n");
	scanf("%d",&pg.big_data_seats);
	assert(pg.big_data_seats<=50);
	printf("\nENTER ML SEATS:\n");
	scanf("%d",&pg.machine_learning_seats);
	assert(pg.machine_learning_seats<=25);
	printf("\nENTER ES SEATS:\n");
	scanf("%d",&pg.embedded_system_seats);
	assert(pg.embedded_system_seats<=25);
	return pg;
}
void display_seats(Program pg){
	printf("\nTOTAL SEATS IN PROGRAM:\n");
	printf("\nBDA SEATS = %d\n",pg.big_data_seats);

	printf("\nML SEATS = %d\n",pg.machine_learning_seats);

	printf("\nES SEATS = %d\n",pg.embedded_system_seats);
}
void display_total_filled_seats(){
	printf("\nTOTAL FILLED SEATS IN RESPECTIVE DEPARTMENTS:\n");
	printf("\nBDA = %d\n",filled_big_data_seats);
	printf("\nML = %d\n",filled_machine_learning_seats);
	printf("\nES = %d\n",filled_embedded_system_seats);
	printf("\nTOTAL = %d\n",total_filled_seats);
}

void student_reg(Student *st){
 	int32_t appnum;
 	int8_t get;
 	printf("\nENTER APPLICATION NUMBER:");
 	scanf("%d",&appnum);
 	printf("\nENTER STUDENT MARKS");
 	scanf("%d",&st[appnum].marks);
 	get=check_status(st[appnum].marks);
 	if(!get){
 		strcpy(st[appnum].status,"ADMITTED");
	 }
	 else{
	 	strcpy(st[appnum].status,"WAITING");;
	 }
 	printf("\nENTER STUDENT NAME:");
 	scanf("%s",&st[appnum].name);
 	printf("\nENTER REGISTRATION NUMBER:");
 	scanf("%d",&st[appnum].regnumber);
 	printf("\nENTER PROGRAM NAME:");
 	scanf("%s",&st[appnum].program);
 	update_seats(st[appnum].program);
 	printf("\nENTER EMAIL ID:");
 	scanf("%s",&st[appnum].email);

 }
 int8_t check_status(int32_t marks){
 	if(marks>5){
 		assert(marks<10);
 		return 0;
	 }
	 else{
	 	return 1;
	 }
 }
 void update_seats(char program[]){
 	assert(strcmp(program,"\0")!=0);
 	if(!strcmp(program,"BDA")){
 		filled_big_data_seats+=1;
 		total_filled_seats=filled_big_data_seats+filled_machine_learning_seats+filled_embedded_system_seats;
	 }
	 else if(!strcmp(program,"ML")){
	 	filled_machine_learning_seats+=1;
	 	total_filled_seats=filled_big_data_seats+filled_machine_learning_seats+filled_embedded_system_seats;
	 }
	 else if(!strcmp(program,"ES")){
	 	filled_embedded_system_seats+=1;
	 	total_filled_seats=filled_big_data_seats+filled_machine_learning_seats+filled_embedded_system_seats;
	 }
	 else{
	 	printf("PLEASE ENTER CORRECT PROGRAM NAME");
	 }

 }
  void display(Student *st){
 	int iteration;

 	for(iteration=1;iteration<=total_filled_seats;iteration++){
 		printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n",st[iteration].name,st[iteration].regnumber,st[iteration].program,st[iteration].email,st[iteration].marks,st[iteration].status);
	 }
 }

  void waiting_students(Student *st){
 	int iteration;
 	for(iteration=1;iteration<=total_filled_seats;iteration++){
 		if(!strcmp(st[iteration].status,"WAITING")){
 			if(!strcmp(st[iteration].program,"BDA") && filled_big_data_seats!=50){
 				strcpy(st[iteration].status,"ACCEPTED");}
 			else if(!strcmp(st[iteration].program,"ML") && filled_machine_learning_seats!=50){
 				strcpy(st[iteration].status,"ACCEPTED");
			 }
			else if(!strcmp(st[iteration].program,"ES") && filled_embedded_system_seats!=50){
 				strcpy(st[iteration].status,"ACCEPTED");
 			}
 			else{
 				strcpy(st[iteration].status,"REJECTED");
			 }
	 }

 	}
}
void display_waiting_students(Student *st){
		int iteration;
 	for(iteration=1;iteration<=total_filled_seats;iteration++){
 		if(!strcmp(st[iteration].status,"WAITING")){
 				printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n",st[iteration].name,st[iteration].regnumber,st[iteration].program,st[iteration].email,st[iteration].marks,st[iteration].status);

		 }

	 }
}
