#include "shell.h"

void read_file()
{
	FILE *f = fopen("history.txt","r");
	char buf[1024];
			
	while(fgets(buf, sizeof(buf), f) != NULL) 
	{
        	printf("%s", buf);
    	}
    			
    	fclose(f); 
}

void write_cmd(char **cmd)
{
	//save the command execution in history
	FILE *f = fopen("history.txt","a");
	fprintf(f,"%s",cmd);
	fclose(f);
}
