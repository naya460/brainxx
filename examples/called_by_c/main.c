#include <stdio.h>

extern int fn15();

int main(void){
    int n = fn15();
    printf("return number : %d\n", n);
    return 0;
}