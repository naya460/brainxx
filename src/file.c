// Copyright 2023 naya460
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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