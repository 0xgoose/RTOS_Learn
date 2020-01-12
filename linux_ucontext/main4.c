#include <ucontext.h>
#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 0x1000

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

static ucontext_t ctx_main, ctx_func1, ctx_func2;

static void func1(void)
{
    while(1);
}

static void func2(void)
{
    while(1);
}

int main() 
{
    char func1_stack[STACKSIZE];
    char func2_stack[STACKSIZE];
    
    getcontext(&ctx_func1);
    ctx_func1.uc_stack.ss_sp = func1_stack;
    ctx_func1.uc_stack.ss_size = sizeof(func1_stack);
    ctx_func1.uc_link = &ctx_main;
    makecontext(&ctx_func1, func1, 0);
    if (swapcontext(&ctx_main, &ctx_func1) == -1)
        handle_error("swapcontext error");
}
