#pragma once

#include <stdio.h>

char *ReadFile(const char *path);

void WriteFile(FILE *file);

void QueueContent(const char *content, ...);