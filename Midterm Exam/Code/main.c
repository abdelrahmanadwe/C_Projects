#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> // For _getch() and _putch()

#include "Midterm_Exam.h"

extern node * head;
int main()
{
	printf("\n\t\t**************************************\n");
	printf("\t\t   Welcome to Midterm Exam System\n");
	printf("\t\t**************************************\n\n");	
		
	while (1)
	{
		int ch;
		printf("SELECT MODE:\n");
		printf("1- Teacher Mode.\n");
		printf("2- Student Mode.\n");
		printf("3- End Exam.\n");
		fflush(stdin);fflush(stdout);
		scanf("%i", &ch);
		
		if(ch == 1)
		{
			teacher_mode();
		}
		else if(ch == 2)
		{
			student_mode();
		}
		else if(ch == 3)
		{
			char password[50];
			printf("Enter password: ");
			
			int j = 0;
			while (1)
			{
				
				char ch = _getch(); // Read a character without echoing
				if (ch == '\r' || ch == '\n')
				{
					password[j] = '\0'; // Null-terminate the password
					break;
				}

				else if (ch == 8 )
				{
					if(j > 0)
					{
						// Handle backspace (delete) key
						printf("\b"); // Move cursor back
						printf(" ");  // Erase the character
						printf("\b"); // Move cursor back again
						j--;          // Decrement index
					}
	
				}
				else
				{
					password[j++] = ch;
					printf("*"); // Display an asterisk for each character
				}
			}
			printf("\n");
			if(strcmp(password, PASSWORD) == 0)
			{

				break;
			}
			else 
			{
				printf("\nPassword is wrong\n");
				printf("\n*****************************************\n\n");
			}
			
		}
		else 
		{
			/* Print A Message For The User To Re Enter The Right Choice */
			printf("\n\n                  ********* Invalid Choice ********* \n");
			printf("             ********* Please Choose the right Mode ********* \n\n");

		}
		
	}
	
	while(head != NULL)
	{
		
		node * ptr = head;
		head = head->next;
		free(ptr);
		
	}
	
	return 0;
}