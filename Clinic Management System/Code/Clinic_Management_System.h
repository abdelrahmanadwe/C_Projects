

#ifndef _Clinc_Mangement_System_H_
#define _Clinc_Mangement_System_H_
 
struct info
{
	int ID;
	int slot;
	int age ;
	char name[100] ;
	char gender[20];
	
};

typedef struct node
{
	struct info patient;
	struct node * next;
}Node;


#define PASSWORD "1234"


void Convert_ToLower(char*);

/*admin mode functions*/
void Admin_Mode(void);
void Add_New_Patient();
void Edit_Patient();
void Reserve_Slot();
void Cancel_Reservation();

/*user mode functions*/
void User_Mode(void);
void View_Patient(void);
void View_Reservations(void);

#endif /* _Clinc_Mangement_System_H_ */