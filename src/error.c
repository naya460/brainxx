#include <stdio.h>
#include <stdlib.h>

void Error(int return_num, const char *error_text){
    fprintf(stderr, "error %d : ", return_num);
    fprintf(stderr, "%s", error_text);
    exit(return_num);
}