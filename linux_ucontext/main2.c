#include <stdio.h>
#include <ucontext.h>

ucontext_t signal_context; 

main()
{
   // while(1);
    printf("%d \n", getcontext(&signal_context));
}
