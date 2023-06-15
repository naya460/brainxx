#pragma once

#include <stdio.h>

char *ReadFile(const char *path);

void WriteFile(const char *path);

void QueueContent(const char *content, ...);