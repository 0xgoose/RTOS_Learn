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

// prymitywna metoda, ale póki co musi wystarczyć
// zanim dojdę do bardziej dynamicznego dodawania
// zadań. Obecnie jest statycznie z góry zdefiniowana
// ilość zadań i licznik. Proste mechanizmy...
volatile int task_counter = 0;
volatile int *tasks[MAX_TASKS];
volatile int *current_task;

volatile char c;

typedef struct {
    __OS_TYPE_SIZE__ sp;
} os_context_t;

typedef struct {
    os_context_t ctx;
    __OS_TYPE_SIZE__ *ptr;
    // jeśli jest tasks jako globalna zmienna z określoną
    // wartością tablicy, gdzie parametr ten określa macro
    // MAX_TASKS, wtedy ta lista zabiera zbędne miejsce.
    // Jeśli tasks wypali, wtedy to trzeba usunć ze strktury.
    // Ale zastanawiam sie jak nie ograniczać ilości zadań... 
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

void os_switch_contex(int num) 
{
    // store context current task
    // get next task from list
    // restore context new task
    context_store();
    
    /*
    int i, current;
    for (i = 0; i < task_counter; i++) {
        // czy to jest potrzebne?
        // Być może zmienna globalna z obecnym zadaniem
        // przyda sie w innej części kodu, więc niech będzie
        // dla testu. Potem się zobaczy.
        current_task = tasks[i]; 
        
        // Ok, co teraz. Nie mam wybierania zadania 
        // według priorytetu itp. mechanizmu. Ma być proste
        // przełączanie kotekstu, wybierając po koleii zadania.
        
    }
    */

    if (c <= task_counter && c >= 0) 
        current_task = tasks[c]; 
    
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
    
    tasks[task_counter++] = t;
    
    // trap
    //while(1);
}

void os_add_task_to_list(os_task_t *task, os_stats_tt *stats, void *stack, void *t)
{
    task->list[stats->num_of_tasks] = t;
    task->ptr = t;
    os_task_init(task, stats, stack, t);
    stats->num_of_tasks++;
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
    char i, j;
    char buff[100];
    
    //task = &task_t;   
    //stats = &stats_t;
    //stats->os_task_list_size = sizeof(task->sp);
    os_add_task_to_list(&task_1, &stats_1, stack_task1, task1);
    os_add_task_to_list(&task_2, &stats_2, stack_task2, task2);
    
    do {
        os_switch_contex(c = c - 48);
        printf("%d %p %p %p\n", c, current_task, task1, task2);
    } while ((c = getchar()) != 'q');
    
    
    return 0;
}
