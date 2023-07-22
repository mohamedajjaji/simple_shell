#ifndef S_SHELL_H
#define S_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void error_handling(const char *message);
void exec_cmd(const char *cmd);
void shell(void);

#endif
