#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

void find_and_delete_terraria_files(char *initial_folder_path);
bool compare_arrays(void *arr1, void *arr2, size_t start, size_t count, size_t element_size);

void change_console_color(HANDLE console_handle, WORD colors);