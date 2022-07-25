#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

void find_and_delete_terraria_files(char *initial_folder_path);
void change_console_color(HANDLE console_handle, WORD colors);
void iterate_through_folder(HANDLE folder_hwnd, char *path_folder);
void process_file_information();