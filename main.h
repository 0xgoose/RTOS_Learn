#include <stdio.h>

typedef struct {
    int sp;
} os_context_t;

typedef struct {
    os_context_t stack;
} os_task_t;

//extern os_task_t task_idle;

