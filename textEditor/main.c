#include <stdio.h>
#include <string.h>

void edit_line(char* buffer, int current_line)
{

    for (int i = 0; i < current_line; i++)// goint at line that user wants to edit.. 
    {
        buffer = strchr(buffer, '\n') + 1;
    }

    char* line_end = strchr(buffer, '\n');
    char saved[1024] = { 0 };
    
    strcpy(saved, line_end);
    scanf("%s", buffer);
    strcpy(buffer + strlen(buffer), saved);
}

void main(int argc, char** argv) 
{
    //opening file with given argument	
    FILE* f = fopen(argv[1], "r");
    
    //defining buffer to save content of file in it..
    char buffer[1024] = {0};
    
    //reading content of file..
    fread(buffer, 1024, 1, f); 
    
    fclose(f);
    
    printf("Content:\n%s\n", buffer);//printing content of file..
    
    int current_line = 0;
    
    scanf("%d", &current_line);//asking for line which user wants to edit
    edit_line(buffer, current_line);//editing line with taking new string..
    f = fopen(argv[1], "w");
    fwrite(buffer, strlen(buffer), 1, f);//rewriting buffer to that file
    
    fclose(f);
}
