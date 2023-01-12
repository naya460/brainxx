#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void OpenFile(const char *path){
    // open file
    FILE *file;
    file = fopen(path, "r");
    if (file  == NULL) exit(2);

    // get file size
    struct stat status;
    if (stat(path, &status) != 0) exit(3); 
    long size = status.st_size;

    // read file
    char *str = (char*)malloc(sizeof(char) * (size + 1));
    int read_count = fread(str, sizeof(char), size + 1, file);
    if (read_count == 0) exit(4);
    str[read_count + 1] = '\0';
    printf("%s\n", str);

    // close file
    fclose(file);

    // free
    free(str);
}

int main(int argc, char **argv){
    if (argc < 2) exit(1);
    OpenFile(argv[1]);
    return 0;
}