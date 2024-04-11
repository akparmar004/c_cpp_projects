#include<stdio.h>
#include<stdlib.h>


#ifdef _WIN32
#include<string.h>

static char buffer[2048];

//fake readline function for windows not from readline.h
char* readline(char *prompt)
{
	fputs(prompt,stdout);
	fgets(buffer,2048,stdin);
	char *cpy = malloc(strlen(buffer)+1);
	strcpy(cpy,buffer);
	cpy[strlen(cpy)-1] = '\0';
	
	return cpy;
}

//fake add_history function
void add_history(char *unused) {}

#else

#include <editline/readline.h>
#include <editline/history.h>

#endif


int main(int argc,char **argv)
{
	//print version details and exit information
	puts("Jarvis Version 0.0.1");
	puts("Press ctrl+c to Exit\n");
	
	//infinite loop
	while(1)
	{
		//print prompt everytime..  and get input
		char* input = readline("jarvis> ");
		
		//add input to history
		add_history(input);
		
		//print input back to user
		printf("No you're a %s\n",input);
		
		free(input);
	}
	
	return 0;
}
