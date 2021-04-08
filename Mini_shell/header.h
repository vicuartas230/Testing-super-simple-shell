#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>

extern char **environ;

char *_getenv(const char *var);
int _strncmp(char *s1, char *s2, size_t n);
char *_strchr(char *s, char c);
char *_strtok(char *str, const char *delim);
int _strlen(char *s);
int counter_words(char * buff);
char **fill2pointer(int word, char *s, char *delim);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif
