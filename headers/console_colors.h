#include <windows.h>

#define F_BLACK 0
#define F_DARKBLUE FOREGROUND_BLUE
#define F_DARKGREEN FOREGROUND_GREEN
#define F_DARKCYAN FOREGROUND_GREEN | FOREGROUND_BLUE
#define F_DARKRED FOREGROUND_RED
#define F_DARKMAGENTA FOREGROUND_RED | FOREGROUND_BLUE
#define F_DARKYELLOW FOREGROUND_RED | FOREGROUND_GREEN
#define F_DARKGRAY FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define F_GRAY FOREGROUND_INTENSITY
#define F_BLUE FOREGROUND_INTENSITY | FOREGROUND_BLUE
#define F_GREEN FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define F_CYAN FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE
#define F_RED FOREGROUND_INTENSITY | FOREGROUND_RED
#define F_MAGENTA FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE
#define F_YELLOW FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN
#define F_WHITE FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE

#define B_BLACK 0
#define B_DARKBLUE BACKGROUND_BLUE
#define B_DARKGREEN BACKGROUND_GREEN
#define B_DARKCYAN BACKGROUND_GREEN | BACKGROUND_BLUE
#define B_DARKRED BACKGROUND_RED
#define B_DARKMAGENTA BACKGROUND_RED | BACKGROUND_BLUE
#define B_DARKYELLOW BACKGROUND_RED | BACKGROUND_GREEN
#define B_DARKGRAY BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE
#define B_GRAY BACKGROUND_INTENSITY
#define B_BLUE BACKGROUND_INTENSITY | BACKGROUND_BLUE
#define B_GREEN BACKGROUND_INTENSITY | BACKGROUND_GREEN
#define B_CYAN BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE
#define B_RED BACKGROUND_INTENSITY | BACKGROUND_RED
#define B_MAGENTA BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE
#define B_YELLOW BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN
#define B_WHITE BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE