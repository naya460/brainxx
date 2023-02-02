#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "error.h"

char *ReadFile(const char *path){
    // open file
    FILE *file;
    file = fopen(path, "r");
    if (file  == NULL) Error(2, "failed to open the file\n");

    // get file size
    struct stat status;
    if (stat(path, &status) != 0) Error(2, "failed to get file size\n");
    long size = status.st_size;

    // read file
    char *str = (char*)malloc(sizeof(char) * (size + 1));
    int read_count = fread(str, sizeof(char), size + 1, file);
    if (size != read_count) Error(2, "failed to read file\n");
    str[read_count + 1] = '\0';

    // close file
    fclose(file);

    return str;
}