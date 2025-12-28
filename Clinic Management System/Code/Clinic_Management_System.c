#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include"Clinc_Mangement_System.h"

int slots[5] = {0};
Node * head = NULL;


void Convert_ToLower(char* str) 
{
    int i = 0;
    while (str[i] != '\0') 
	{
		switch (str[i])
		{
			case 'A' ... 'Z' : str[i] +=32 ; break ;
		}
        
        i++;
    }
}

void Admin_Mode()
{
	int x;
	
	start:
	printf("0) Exit \n");
	printf("1) Add new patient record. \n");
	printf("2) Edit patient record. \n");
	printf("3) Reserve a slot with the doctor. \n");
	printf("4) Cancel reservation. \n");
	printf("what do you want to do ( 0 or 1 or 2 or 3 or 4 ) : ");
	
	scanf("%d",&x);
	
	switch(x)
	{
	case 0 :
		printf("\n*****************************************\n\n");
		break;
		
	case 1 :
	
		printf("\n*****************************************\n\n");
		/* Call Add New Patient Informations Function To The Clinic Database */
		Add_New_Patient(); 
		break;
		
	case 2 :
	
		printf("\n*****************************************\n\n");
		/* Call Edit Patient Informations Function In The Clinic Database */
		Edit_Patient(); 
		break;
	case 3 :
	
		printf("\n*****************************************\n\n");
		/* Call Reserve Slot With A Doctor Function For Certain Patient  */
		Reserve_Slot(); 
		break;
	case 4 : 
	
		printf("\n*****************************************\n\n");
		/* Call Cancel The Reservation Of Doctor Function For Certain Patient */
		Cancel_Reservation(); 
		break;
	default :
		printf("\n\n                     ********* Invalid Choice ********* \n");
        printf("             ********* Please Choose the right action ********* \n\n");
		goto start;
	}
	
}


void User_Mode()
{
	int x;
	
	lable :
	printf("0) Exit \n");
	printf("1) View patient record \n");
	printf("2) View today\\'s reservations \n");
	printf("what do you want to do ( 0 or 1 or 2 ) : ");
	
	
	scanf("%d",&x);
	switch(x)
	{
	case 0 :
	
		printf("\n*****************************************\n\n");
		break;
		
	case 1 :
	
		printf("\n*****************************************\n\n");
		/* Call The View Patient Informations Function */
		View_Patient();
		break;
		
	case 2 :
	
		printf("\n*****************************************\n\n");
		/* Call The View Reservations Function */
		View_Reservations();
		break; 
		
	/*If The User Enter Wrong Choice Print A message To Re Choose The Right Action*/
	default :
		 printf("                     ********* Invalid Choice ********* \n");
         printf("             ********* Please Choose The Right Action ********* \n");
		 goto lable;
	}
	
}

void Add_New_Patient()
{
	Node * newpatient = (Node * )malloc(sizeof(Node));
	if(newpatient == NULL)
	{
		printf("Memory was not allocated\n");
		
	}
	else 
	{
		newpatient->next = head;
		head = newpatient;
		
		printf("enter the name : ");
		fflush(stdin);fflush(stdout);
		fgets(head->patient.name,100,stdin);
		
		printf("enter the age : ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&(head->patient.age));
		
		printf("enter the gender : ");
		fflush(stdin);fflush(stdout);
		fgets(head->patient.gender,20,stdin);
		
		printf("enter the ID : ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&(head->patient.ID));
		
		head->patient.slot = 0;
		printf("\n*****************************************\n\n");
	}

	

}

void Edit_Patient()
{
	Node *ptr = head;
	if(ptr == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
	else 
	{
		int id;
	
		printf("enter the ID : ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&id);
		
		while(ptr!= NULL && (ptr->patient.ID) != id)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			printf("ID Not Found\n");
		}
		else
		{
			
			printf("enter the name : ");
			fflush(stdin);fflush(stdout);
			fgets(ptr->patient.name,100,stdin);
			
			printf("enter the age : ");
			fflush(stdin);fflush(stdout);
			scanf("%d",&(ptr->patient.age));
			
			printf("enter the gender : ");
			fflush(stdin);fflush(stdout);
			fgets(ptr->patient.gender,20,stdin);
			
			printf("enter the ID : ");
			fflush(stdin);fflush(stdout);
			scanf("%d",&(ptr->patient.ID));
		
		}
		
	}
	
	printf("\n*****************************************\n\n");

}

void Reserve_Slot()
{
	Node *ptr = head;
	
	if(ptr == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
	else 
	{
		if(slots[0]==1 && slots[1]==1 && slots[2]==1 && slots[3]==1 && slots[4]==1)
		{
			printf("No slot is available \n");
			printf("\n*****************************************\n\n");
			return;
		}
		else
		{
			printf("the available slots :-\n");
		}
		printf("0) Exit \n");
		if(slots[0] == 0)
		{
			printf("1) 2pm to 2:30pm\n");
		}
		if(slots[1] == 0)
		{
			printf("2) 2:30pm to 3pm\n");
		}
		if(slots[2] == 0)
		{
			printf("3) 3pm to 3:30pm\n");
		}
		if(slots[3] == 0)
		{
			printf("4) 4pm to 4:30pm\n");
		}
		if(slots[4] == 0)
		{
			printf("5) 4:30pm to 5pm\n");
		}
		
	
		int id;
		
		printf("enter the ID : ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&id);
		
		while(ptr!= NULL && (ptr->patient.ID) != id)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			printf("ID Not Found\n");
		}
		else
		{
			if((ptr->patient.slot) >= 1 && (ptr->patient.slot) <= 5)
			{
				slots[(ptr->patient.slot)-1] = 0;
			}
			printf("enter the slot : ");
			fflush(stdin);fflush(stdout);
			scanf("%d",&(ptr->patient.slot));
			
			if((ptr->patient.slot) == 0)
			{
				printf("\n*****************************************\n\n");
				return;
			}
			if( (ptr->patient.slot) >= 1 && (ptr->patient.slot) <= 5 )
			{
				if(slots[(ptr->patient.slot)-1] == 0 )
				{
					slots[(ptr->patient.slot)-1] = 1;
					printf("successfully registered\n");
				}
				else
				{
					printf("This slot is't available \n");
				}
		
			}
			else
			{
				ptr->patient.slot = 0;
				printf("This slot is't available \n");
			}
	
		}
		
	}
	
	printf("\n*****************************************\n\n");
      
}

void Cancel_Reservation()
{
	
	Node *ptr = head;
	
	if(ptr == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
	else 
	{
		int id;
	
	
		printf("enter the ID : ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&id);
		
		while(ptr!= NULL && (ptr->patient.ID) != id)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			printf("ID Not Found\n");
		}
		else
		{
	
			if( (ptr->patient.slot) >= 1 && (ptr->patient.slot) <= 5 )
			{
				
				slots[(ptr->patient.slot)-1] = 0;
				ptr->patient.slot = 0;
				printf("Reservation cancelled. Success\n");
				
			}
			
		}
		
	}
	
	printf("\n*****************************************\n\n");
}

void View_Patient()
{
	Node *ptr = head;
	if(ptr == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
	else 
	{
		int id;
	
		printf("enter the ID : ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&id);
		
		while(ptr!= NULL && (ptr->patient.ID) != id)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			printf("ID Not Found\n");
		}
		else
		{
			printf("Name   : %s\n",(ptr->patient.name));
			printf("Age    : %d\n",(ptr->patient.age));
			printf("Gender : %s\n",(ptr->patient.gender));
			printf("ID     : %d\n",(ptr->patient.ID));
		}
		
	}
	
	printf("\n*****************************************\n\n");
	
}
void View_Reservations()
{
	Node *ptr = head;
	if(ptr == NULL)
    {
        /* Check If There Is Patients Informations In The Database Or Not If Not Print This Message For The User */
        printf("\nThere are no patients.\n");
    }
	else
	{
		while(ptr!= NULL )
		{
			printf("ID : %d\t",(ptr->patient.ID));
			
			switch((ptr->patient.slot))
			{
				case 1 : printf(" 2pm to 2:30pm\n"); break;
				case 2 : printf(" 2:30pm to 3pm\n"); break;
				case 3 : printf(" 3pm to 3:30pm\n"); break;
				case 4 : printf(" 4pm to 4:30pm\n"); break;
				case 5 : printf(" 4:30pm to 5pm\n"); break;
				default: printf(" nothing\n");
			}
			ptr = ptr->next;
		}
	}
	printf("\n*****************************************\n\n");

}