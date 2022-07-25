#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <limits.h>
#include <time.h>

#include "main.h"
#include "console_colors.h"

char original_header[] =
    {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A, 0x00, 0x00, 0x00, 0x0D, 0x49, 0x48, 0x44, 0x52, 0x00, 0x00};

int current_depth = -1;
int max_depth = INT_MAX;
WIN32_FIND_DATA find_data;

char sub_f_path[512];

char path_output_file[22];
FILE *paths_file;

HANDLE console_hwnd;
WORD old_console_colors;

int main()
{
    console_hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO temp;
    GetConsoleScreenBufferInfo(console_hwnd, &temp);
    old_console_colors = temp.wAttributes;

    sprintf(path_output_file, "paths-%lu.txt", GetTickCount64());
    paths_file = fopen(path_output_file, "ab+");
    printf("input the initial folder path : ");
    char buffer[512];
    gets(buffer);

    find_and_delete_terraria_files(buffer);

    fclose(paths_file);

    change_console_color(console_hwnd, old_console_colors);
    printf("shit's done, chief");
    gets(buffer);
}

void find_and_delete_terraria_files(char *initial_folder_path)
{
    if (current_depth >= max_depth)
    {
        return;
    }
    current_depth += 1;

    char full_p_w_astrk[512];
    sprintf(full_p_w_astrk, "%s\\*", initial_folder_path);

    change_console_color(console_hwnd, old_console_colors);
    printf("currently at %s, depth : %d\n", initial_folder_path, current_depth);

    HANDLE folder_hwnd = FindFirstFile(full_p_w_astrk, &find_data);
    if (folder_hwnd == INVALID_HANDLE_VALUE)
    {
        change_console_color(console_hwnd, F_RED);
        printf("tbh L it errored(%d)\n", GetLastError());
        return;
    }

    iterate_through_folder(folder_hwnd, initial_folder_path);

    FindClose(folder_hwnd);
    current_depth -= 1;
}

void iterate_through_folder(HANDLE folder_hwnd, char *path_folder)
{
    do
    {
        int fdr_flags = strcmp(find_data.cFileName, ".") == 0 || strcmp(find_data.cFileName, "..") == 0;
        if (fdr_flags)
        {
            continue;
        }

        sprintf(sub_f_path, "%s\\%s", path_folder, find_data.cFileName);
        if (find_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            find_and_delete_terraria_files(sub_f_path);
        }
        else
        {
            process_file_information();
        }
    } while (FindNextFileA(folder_hwnd, &find_data));
}

void process_file_information()
{
    int header_size_b = sizeof(original_header);
    char file_header[header_size_b];

    FILE *file_being_read = fopen(sub_f_path, "rb");
    fread(file_header, 1, header_size_b, file_being_read);
    fclose(file_being_read);
    
    if (memcmp(file_header, original_header, header_size_b) == 0)
    {
        change_console_color(console_hwnd, F_GREEN);
        printf("%s has a valid header!\n", find_data.cFileName);

        char file_contents[512];
        sprintf(file_contents, "%s\n", sub_f_path);
        fseek(paths_file, 0, SEEK_END);
        fwrite(file_contents, 1, strlen(file_contents), paths_file);
    }
    else
    {
        change_console_color(console_hwnd, F_YELLOW);
        printf("%s does not have a valid header.\n", find_data.cFileName);
    }
}

void change_console_color(HANDLE console_handle, WORD colors)
{
    SetConsoleTextAttribute(console_handle, F_WHITE | B_BLACK);
    SetConsoleTextAttribute(console_handle, colors);
}