#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdarg.h>

#include "error.h"

typedef struct Queue Queue;
struct Queue {
    char *text;
    Queue *next;
};

static Queue *queue = NULL;
static Queue *qend = NULL;

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
    char *str = (char*)calloc(sizeof(char), (size + 1));
    int read_count = fread(str, sizeof(char), size, file);
    if (size != read_count) Error(2, "failed to read file\n");
    str[read_count] = '\0';

    // close file
    fclose(file);

    return str;
}

void WriteFile(const char *path){
    // open file
    FILE *file = NULL;
    file = fopen(path, "w");
    if (file  == NULL) Error(2, "failed to open the file\n");

    // write file
    Queue *tmp = queue;
    while (tmp != NULL) {
        fprintf(file, "%s", tmp->text);
        tmp = tmp->next;
    }

    // close file
    fclose(file);
}

void QueueContent(const char *content, ...){
    static char str[100] = { 0 };

    // generate the string
    va_list ap;
    va_start(ap, content);
    vsnprintf(str, 100, content, ap);
    va_end(ap);

    // create a next queue
    Queue *tmp = (Queue*)calloc(sizeof(queue), 1);
    tmp->text = (char*)calloc(sizeof(char), strlen(str));
    strcpy(tmp->text, str);

    if (queue == NULL) {
        queue = tmp;
        qend = tmp;
        return;
    }

    // connect the queue
    qend->next = tmp;
    qend = tmp;
}