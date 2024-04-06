#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	char name[30];
	char dob[11]; //dd/mm/yyyy
	char fatherName[30];
	char city[10];
	struct student *next;
} stud;

stud *head = NULL;
stud *tail = NULL;

void addStud()
{
	getchar();
	stud *temp = malloc(sizeof(stud));
	printf("Enter the name of student : ");
	scanf("%[^\n]s",temp -> name);
	getchar();

	printf("Enter DOB in format(dd/mm/yyyy) : ");
	scanf("%[^\n]s",temp -> dob);	
	getchar();

	printf("Enter father name : ");
	scanf("%[^\n]s",temp -> fatherName);
	getchar();

	printf("Enter city name : ");
	scanf("%[^\n]s",temp -> city);
	getchar();

	temp -> next = NULL;

	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail -> next = temp;
		tail = temp;
	}
}
	
void display_all_student()
{
	stud *temp = head;
	if(head == NULL)
	{
		printf("List is empty..\n");
	}
	else
	{
		while(temp != NULL)
		{
			
			printf("\nStudent Name : %s\nDOB : %s\nFather Name : %s\nCity : %s\n\n",temp -> name,temp -> dob, temp -> fatherName, temp -> city);
			temp = temp -> next;
		}
	}
}


void delete_all_students()
{
	if(head == NULL)
		printf("List is already empty..\n");
	else
	{
		long count = 0;
		stud *temp = head;
		while(temp)
		{
			stud *t = temp -> next;
			free(temp);
			temp = t;
			count++;	
		}
		head = NULL;
		printf("%ld nodes succesfully deleted..\n",count);
	}
}

int main()
{
	int choice = 1;

	while(choice != 0)
	{
		printf("\n********* Main Menu *********\n");
		printf("\tPress 1 to add student\n");
		printf("\tPress 2 to display all students\n");
		printf("\tPress 3 to delete all students\n");
		printf("\tPress 0 to exit..\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);	
		
		switch(choice)
		{
			case 1: addStud(); 
				break;
			case 2: display_all_student(); 
				break;
			case 3: delete_all_students();
				break;
			case 0: exit(1);

			default : printf("\nInvalid choice..  Please input a valid number..\n");
				  getchar();
		}
	}
	return 0;
}
