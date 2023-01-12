#include <stdio.h>
#include <stdlib.h>

void OpenFile(const char *path){
    FILE *file;
    file = fopen(path, "r");
    if (file  == NULL) exit(2);
    fclose(file);
}

int main(int argc, char **argv){
    if (argc < 2) exit(1);
    OpenFile(argv[1]);
    return 0;
}