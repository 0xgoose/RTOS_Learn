/**
    os_schedule - dzienik zadań
    os_add_task_to_schedule - dodaj zadanie do listy zadań
    idle_task - pierwsze zadanie, zadanie bezczynności
    ..
*/

#include <stdint.h>
#include <stdio.h>

#define STACK_SIZE 64
#define MAX_TASKS 100

#define __OS_TYPE_SIZE__ uint64_t
#define __IO__ volatile

#define context_store() \
    __asm__ __volatile__( \
        "push %rax \n\t" \
        "push %rbx \n\t" \
        "push %rcx \n\t" \
        "push %rdx \n\t" \
        "push %rsi \n\t" \
        "push %rdi \n\t" \
        "push %rbp \n\t" \
        "push %rsp \n\t" \
        "push %r8 \n\t" \
        "push %r9 \n\t" \
        "push %r10 \n\t" \
        "push %r11 \n\t" \
        "push %r12 \n\t" \
        "push %r13 \n\t" \
        "push %r14 \n\t" \
        "push %r15 \n\t" \
    )

#define context_restore() \
    __asm__ __volatile__( \
        "pop %r15 \n\t" \
        "pop %r14 \n\t" \
        "pop %r13 \n\t" \
        "pop %r12 \n\t" \
        "pop %r11 \n\t" \
        "pop %r10 \n\t" \
        "pop %r9 \n\t" \
        "pop %r8 \n\t" \
        "pop %rsp \n\t" \
        "pop %rbp \n\t" \
        "pop %rdi \n\t" \
        "pop %rsi \n\t" \
        "pop %rdx \n\t" \
        "pop %rcx \n\t" \
        "pop %rbp \n\t" \
        "pop %rax \n\t" \
    )

static __OS_TYPE_SIZE__ stack_task1[STACK_SIZE];
static __OS_TYPE_SIZE__ stack_task2[STACK_SIZE];

volatile int test = 0;

typedef struct {
    __OS_TYPE_SIZE__ sp;
} os_context_t;

typedef struct {
    os_context_t ctx;
    __OS_TYPE_SIZE__ *ptr;
    int *list[MAX_TASKS];    
} os_task_t;

typedef struct {
    __IO__ int num_of_tasks;
    __IO__ int os_task_list_size;
} os_stats_tt;

os_task_t task_idle, task_1, task_2;
os_stats_tt stats_idle, stats_1, stats_2;

void os_schedule()
{
    
}

void os_switch_contex() 
{
    // store context current task
    // get next task from list
    // restore context new task
    context_store();
    
    /*
    if (test > 0) {
        asm volatile ("call task2");
        test = 0;
    } else {
        asm volatile ("call task1");
        test++;
    }
    */
    
    context_restore();
    
}

void os_task_init(os_task_t *task, os_stats_tt *stats, void *stack_param, void *t)
{
    
    // tylko nie wiem po co jest to -1. Możliwe że jest to offset
    // dla wrzucenia rbp albo coś takiego, bo wejście do każdej
    // funkcji powoduje że na stos wrzucany jest rejestr rbp albo rsp
    __OS_TYPE_SIZE__ *stack = ((__OS_TYPE_SIZE__*)stack_param) + sizeof(task) - 1;
    
    // acha, bo ten kod wyżej najpierw pobiera adres stack_param
    // ale potem własnie musi zrobić skok pod adres przenusnięty o wielkość
    // struktury zadania. Dlatego jest + sizeof(task). W rados jest to 
    // zdefiniowane w argumencie, a tutaj dostaję już gotową wartość
    // z kolei ja robię to na szybko więc obliczyłem to w tej linijce
    // i w ten sposób kod niżej leci od dołu do góry, wypełniając
    // te fragment pamięci, aż do początkowego adresu stack_param
    // który został podany w argumencie funckji. Dlatego m.in. jest
    // *(stack--), czyli dekremantacja do tyłu, własnie żeby wrócić
    // do tego adres stack_param. Czyli kórtko mówiąc robię offset o
    // wilekość struktury i potem wypełniam tym co jest niżej w tył.
    // *(stack--) = 0xff;
    // *(stack--) = (__OS_TYPE_SIZE__)(t);
    // ...
    
    task->ctx.sp = (__OS_TYPE_SIZE__)stack;
    
    // trap
    while(1);
}

void os_add_task_to_list(os_task_t *task, os_stats_tt *stats, void *stack, void *t)
{
    task->list[stats->num_of_tasks] = t;
    task->ptr = t;
    stats->num_of_tasks++;
    os_task_init(task, stats, stack, t);
}

void idle_task()
{
    while(1);
}  

int task1()
{
    int i, j;
    for (i = 0; i < 10; i++) {
        j = i;
    }
    return j;
} 

int task2()
{
    int i, j = 0;
}

int main()
{
    char c, j;
    char buff[100];
    
    int i;
    //task = &task_t;   
    //stats = &stats_t;
    //stats->os_task_list_size = sizeof(task->sp);
    os_add_task_to_list(&task_1, &stats_1, stack_task1, task1);
    os_add_task_to_list(&task_2, &stats_2, stack_task2, task2);
    
    while(1) {
        os_switch_contex();
    }
    
    
    return 0;
}
