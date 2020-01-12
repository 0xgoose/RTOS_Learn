#include "main.h"


void idle_task()
{
    
}

main()
{
    set_ctx();
    printf("%lu \n", sizeof(os_task_t));
    idle_task();
}
