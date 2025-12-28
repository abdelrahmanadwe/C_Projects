#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> // For _getch() and _putch()
#include "Clinc_Mangement_System.h"

extern Node * head;
int main()
{
	
	printf("\n\t\t********************************************\n");
	printf("\t\t   Welcome to Hospital Management System\n");
	printf("\t\t********************************************\n\n");
	char mode[50];
	char pass[50];
		
	while(1)
	{
		
		printf("please choose the mode(admin or user or exit ) : ");
		fflush(stdin);fflush(stdout);
		scanf("%s",mode);
		Convert_ToLower(mode);
		
		if(strcmp(mode,"admin") == 0)
		{
			int i = 0 ;
	
			do{
				if(i>0)
				{
					printf("\nWrong Password ......... you have %d times\n", 3-i );
				}
				
				/*get the password from admin */
				printf("please enter your password : ");
				fflush(stdin);fflush(stdout);
				
				int j = 0;
				while (1)
				{
					
					char ch = _getch(); // Read a character without echoing
					if (ch == '\r' || ch == '\n')
					{
						pass[j] = '\0'; // Null-terminate the password
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
						pass[j++] = ch;
						printf("*"); // Display an asterisk for each character
					}
				}
				printf("\n");
	
				/*cheeck the password */
				if(strcmp(pass,PASSWORD) == 0)
				{
					printf("password is correct\n");
					printf("\n\n*****************************************\n\n");
	
					Admin_Mode();
					break;
				}
				
				i++;
				
			}while(i<3);
			
		}
		else if(strcmp(mode,"user") == 0)
		{
			printf("\n\n*****************************************\n\n");
			User_Mode();
		}
		else if(strcmp(mode,"exit") == 0)
		{
			
			/*get the password from admin */
			printf("Please enter the password : ");
			fflush(stdin);fflush(stdout);
			
			int j = 0;
			while (1)
			{
				
				char ch = _getch(); // Read a character without echoing
				if (ch == '\r' || ch == '\n')
				{
					pass[j] = '\0'; // Null-terminate the password
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
					pass[j++] = ch;
					printf("*"); // Display an asterisk for each character
				}
			}
			printf("\n");
			
			
			printf("\n\n*****************************************\n\n");
			/*cheeck the password */
			if(strcmp(pass,PASSWORD) == 0)
			{
							
				break;
			}
			else
			{
				printf("Password is wrong\n");
			}
			printf("\n*****************************************\n\n");
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
		
		Node * ptr = head;
		head = head->next;
		free(ptr);
		
	}
	
	return 0;
	
}