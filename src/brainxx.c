#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void Error(int return_num, const char *error_text){
    fprintf(stderr, "error %d : ", return_num);
    fprintf(stderr, "%s", error_text);
    exit(return_num);
}

void OpenFile(const char *path){
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
    printf("%s\n", str);

    // close file
    fclose(file);

    // free
    free(str);
}

int main(int argc, char **argv){
    if (argc < 2) Error(1, "arguments are less than 2\n");
    OpenFile(argv[1]);
    return 0;
}