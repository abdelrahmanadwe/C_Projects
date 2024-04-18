#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // For _getch() and _putch()

#include "Midterm_Exam.h"

node * head = NULL;

int Level_count[4]={0};

// calculate number of student
int student_count = 0;


// function to Teacher Mode
void teacher_mode()
{
	
	int j = 0;
	char username[50];
	char password[50];
	start :
	
	
	printf("Please Enter Your Username and Password:-\n");
	printf("Enter username: ");
	scanf("%s", username);
	printf("Enter password: ");
	
	int i = 0;
	while (1)
	{
		
		char ch = _getch(); // Read a character without echoing
		if (ch == '\r' || ch == '\n')
		{
			password[i] = '\0'; // Null-terminate the password
			break;
		}
		else if (ch == 8 )
		{
			if(i > 0)
			{
				// Handle backspace (delete) key
				printf("\b"); // Move cursor back
				printf(" ");  // Erase the character
				printf("\b"); // Move cursor back again
				i--;          // Decrement index
			}
		}
		else
		{
			password[i++] = ch;
			printf("*"); // Display an asterisk for each character
		}
		
	}
	printf("\n");
	
	if (strcmp(username, USER_NAME) == 0 && strcmp(password, PASSWORD) == 0) // check is name and password are correct or not
	{
		printf("\n\n----------------------------------------------------------\n\n");
		printf("Hello...\n\n");
		while (1)
		{
			
			int ch;
			printf("\nSELECT CHOOSE: \n");
			printf("1- Add Student.\n");
			printf("2- Print Report.\n");
			printf("3- Exit.\n");
			fflush(stdin);fflush(stdout);
			scanf("%i", &ch);
			if(ch == 1)
			{
				add_student();
			}
			else if(ch == 2)
			{
				print_report();
			}
			else if(ch == 3)
			{
				
				break;
			}
			else 
			{
				
				/* Print A Message For The User To Re Enter The Right Choice */
				printf("\n\n                  ********* Invalid Choice ********* \n");
				printf("             ********* Please Choose the right Mode ********* \n\n");

			}
		
		}
		
	}
	else
	{
		j++;
		if(j<3)
		{
			printf("\n\n----------------------------------------------------------\n\n");
			printf("Invalid Username or Password ......... you have %d times\n\n",3-j);
			
			goto start;
		}	
		
	}
	printf("\n\n----------------------------------------------------------\n\n");
	
}
// Function to add Student and check if number of student is complete or not
void add_student()
{
	
	node * newstudent = (node *)malloc(sizeof(node));
	
	printf("\n\n----------------------------------------------------------\n\n");

	if(newstudent == NULL)
	{
		
		printf("Memory was not allocated\n");
		
	}
	else 
	{
		
		newstudent->next = head;
		head = newstudent;
	
		printf("Enter Student's ID: ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &(newstudent->student.ID));
		
		printf("Enter Student's Name: ");
		fflush(stdin);fflush(stdout);
		fgets(newstudent->student.name,50,stdin);
		
		
		printf("Enter Student's Level: ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &(newstudent->student.Level));
		
		while((newstudent->student.Level) > 4)
		{
			printf("There are only four levels \n");
			printf("Enter Student's Level: ");
			fflush(stdin);fflush(stdout);
			scanf("%d", &(newstudent->student.Level));
		}
		Level_count[(newstudent->student.Level)-1] ++;
		
		newstudent->student.Grade = 0 ;
			
		student_count++;
		
	} 

}

void student_mode()
{
	int ID;
	node *ptr = head;
	
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf("Enter your ID: ");
	fflush(stdin);fflush(stdout);
	scanf("%i", &ID);
	
	while(ptr!= NULL && (ptr->student.ID) != ID)
	{
		ptr = ptr->next;
	}
	if(ptr == NULL)
	{
		printf("\n\n----------------------------------------------------------\n\n");
		printf("ID Not Found\n");
	}	
	else 
	{
		show_exam(ptr);
	}
	
}

void show_exam(node * ptr)
{
	
	switch (ptr->student.Level)
	{
	case 1:
		PYTHON_exam(ptr);
		break;
	case 2:
		JAVA_exam(ptr);
		break;
	case 3:
		CPP_exam(ptr);
		break;
	case 4:
		C_exam(ptr);
		break;
	}
}
void PYTHON_exam(node * ptr)
{
	char ch;
	
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(PYTHON_Q1);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == PYTHON_A1 || ch == (PYTHON_A1^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(PYTHON_Q2);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == PYTHON_A2 || ch == (PYTHON_A2^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(PYTHON_Q3);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == PYTHON_A3 || ch == (PYTHON_A3^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(PYTHON_Q4);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == PYTHON_A4 || ch == (PYTHON_A4^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(PYTHON_Q5);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	if (ch == PYTHON_A5 || ch == (PYTHON_A5^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
  
}
void C_exam(node * ptr)
{
	int ch;
	printf("\n\n----------------------------------------------------------\n\n");
	printf(C_Q1);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == C_A1 || ch == (C_A1^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(C_Q2);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == C_A2 || ch == (C_A2^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(C_Q3);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == C_A3 || ch == (C_A3^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(C_Q4);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == C_A4 || ch == (C_A4^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(C_Q5);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == C_A5 || ch == (C_A5^(1<<5)))
	{
		ptr -> student.Grade +=4;
	}
  
}

void CPP_exam(node * ptr)
{
	int ch;
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(CPP_Q1);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == CPP_A1 || ch == (CPP_A5^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(CPP_Q2);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == CPP_A2 || ch == (CPP_A2^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(CPP_Q3);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == CPP_A3 || ch == (CPP_A3^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(CPP_Q4);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == CPP_A4 || ch == (CPP_A4^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(CPP_Q5);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == CPP_A5 || ch == (CPP_A5^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
}

void JAVA_exam(node * ptr)
{
	char ch;
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(JAVA_Q1);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == JAVA_A1 || ch == (JAVA_A1^(1<<5)) )
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(JAVA_Q2);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == JAVA_A2 || ch == (JAVA_A2^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(JAVA_Q3);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == JAVA_A3 || ch == (JAVA_A3^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
	printf("\n\n----------------------------------------------------------\n\n");
	printf(JAVA_Q4);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == JAVA_A4 || ch == (JAVA_A4^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	printf("\n\n----------------------------------------------------------\n\n");
	printf(JAVA_Q5);
		
	printf("Answer : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &ch);
	if (ch == JAVA_A5 || ch == (JAVA_A5^(1<<5)))
	{
		 ptr -> student.Grade +=4;
	}
	
}


void print_report()
{
	node * ptr = head;
	if(ptr == NULL)
	{
		printf("\n\n----------------------------------------------------------\n\n");
		printf("                    There are no studets.                     ");
		printf("\n\n----------------------------------------------------------\n\n");
	}
	else 
	{
		for(int ii = 1; ii <=4 ; ii++)
		{
			printf("\n\n --------------------------- Level (%d) ---------------------------\n\n",ii);
			if(Level_count[ii-1] == 0)
			{
				printf("                    There are no studets in level (%d)        ",ii);
				
			}
			else
			{
				for(int i = 20 ; i >=0; i -= 4)
				{
					
					for(int j = 0 ; j <= student_count , ptr != NULL ; j++ , ptr = ptr->next)
					{
						if((ptr->student.Level) == ii && (ptr->student.Grade) == i )
						{
							printf("Name: %s\t\t ID: %d\t\t Grade: %d\n",ptr->student.name,ptr->student.ID,ptr->student.Grade);
						}
						
					}
					ptr = head;
				}
			}
			
				
		}
	}
	
	
}

