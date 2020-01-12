#include "main.h"

void task_idle(void)
{

}

main(void)
{
    set_ctx();
    printf("%lu \n", sizeof(os_task_t));
    task_idle();
}

