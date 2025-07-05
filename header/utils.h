// author: @anvaymayekar
// utils.h - Terminal styling utilities and Platform delay function
// Provides ANSI escape sequences for bold and colored text in CLI.

#ifndef UTILS_H
#define UTILS_H

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"

#define MAX 12

// Pause macro (cross-platform)
#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms) // Windows: ms = milliseconds
#else
#include <unistd.h>
#define SLEEP(ms) usleep((ms) * 1000) // Linux/Unix: ms to microseconds
#endif

#endif
