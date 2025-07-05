// author: @anvaymayekar
// title.h — Cross-platform Terminal Title Setter
// Defines a utility function `set_title()` that sets the terminal window title.
// Supports both Windows (`system("title ...")`) and Linux/macOS (`ANSI escape sequence`) platforms.

#ifndef TITLE_H
#define TITLE_H

#include <stdio.h>
#include <stdlib.h>

void set_title(const char *title)
{
#ifdef _WIN32
    char command[100];
    snprintf(command, sizeof(command), "title %s", title);
    system(command);
#else
    printf("\033]0;%s\007", title); // for linux based systems
    fflush(stdout);
#endif
}

#endif
