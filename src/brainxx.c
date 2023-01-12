#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "error.h"

char *OpenFile(const char *path){
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
    if (read_count == 0) Error(2, "failed to read file\n");
    str[read_count + 1] = '\0';

    // close file
    fclose(file);

    return str;
}

void Compile(char *program){
    while(*program != '\0') {
        putchar(*program);
        ++program;
    }
}

int main(int argc, char **argv){
    if (argc < 2) Error(1, "arguments are less than 2\n");
    Compile(OpenFile(argv[1]));
    putchar('\n');
    return 0;
}