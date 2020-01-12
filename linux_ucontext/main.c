#define _GNU_SOURCE
#include <stdio.h>
#include <signal.h>
#include <ucontext.h>


ucontext_t signal_context; 
ucontext_t *cur_context; 
void *signal_stack;
    
ucontext_t context;
	
void thread1()
{
    
}


void main()
{   	
	getcontext(&context);
	//makecontext(&context, main, 1);
	//context.us_stack.ss_sp = thread1;
	context.uc_mcontext.gregs[REG_RDX] += 0x20;
	puts("Hello world");
	printf("%lu \n", (long int)(greg_t*)context.uc_mcontext.gregs[REG_RDX]);
	sleep(1);
	
	setcontext(&context);
}
