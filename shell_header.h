#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>

/* Prototypes */
int exec_command(char *cmd);
void interactive_mode(void);
void non_interactive_mode(void);
void process_input(char *line);
void parse_arguments(char *cmd, char **argv);
char *find_command_in_path(char *cmd);
int is_exit_command(const char *cmd);
void print_env(char **environ);
ssize_t my_getline(char **line, size_t *n);
char *get_command_path(char *cmd);
size_t custom_strlen(const char *str);

#endif
