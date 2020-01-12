#include <stdint.h>

#define TASK_STACK_SIZE 0x40 // 64B

typedef struct {
    uint64_t sp;
    uint64_t base;   
    uint64_t stack[TASK_STACK_SIZE];
} os_task;

os_task os;
os_task *t; // wksaźnik do struktury

#define example_func2() \
    __asm__ __volatile( \
        "nop \n\t" \
        "ret \n\t" \
    )

void example_func()
{
    example_func2();
}



#define repeat() \
    asm volatile( \
        "add $(1 << 2), %r14 \n\t" \
    )

#define update_struct() \
    asm volatile( \
        "lea os, %rax \n\t" \
        "mov %rsp, 0x0(%rax) \n\t" \
        "mov %rsp, 0x8(%rax) \n\t" \
        "mov %rsp, 0x10(%rax) \n\t" \
    )

void create_task(os_task *task, void *stack, void *proc)
{
    //asm ("call task0");    
    //update_struct();
    task = &os;
    task->sp = 20;
    update_struct();
}

void task0() 
{

}

main()
{  
    //t = &os;
    //update_struct();
    asm ("call example_func");
    create_task(t, &(t->sp), &task0); 
}
