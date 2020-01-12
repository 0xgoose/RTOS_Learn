#include "main.h"

static os_task_t ost;

void set_ctx()
{
    os_task_t *os;
    os = &ost;
    os->stack.sp = 0xff;
}

