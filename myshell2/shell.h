#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#ifndef SHELL_H
#define SHELL_H

void print_prompt1();
void print_prompt2();

char *read_cmd();
void start();
void read_file();
void write_cmd(char**);
#endif
