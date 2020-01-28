/*
 * Więc są rejestry...
 * RIP => steruje instrukcją call
 * RSP => wskaźnik stosu
 */
 
 
 #define TRAP while(1);
 #define NULL 0
 
 // general arch type
 #define __at long long int
 
 // 8 bit value repeat x times 
 // STACK_SIZE 8 * 8 = 64 
 // 20 * 2 (space for 20 elements 64 bits size) = 320
 #define STACK_SIZE 20 * 2
 
 __at volatile current_task;
 __at volatile *__stack__;

typedef struct {
    __at csa; // save current stack address behind store context of current task
} os_system_t;

typedef struct {
  __at ctx;
} os_context_t;

typedef struct {
  os_context_t context;
  void *stack;
  __at stack_size;
  void *proc;
  void *param;
} os_task_t;

// dodaj struktury dla zadań
// pierwsze zadanie to task_idle
os_task_t task_idle, task1, task2;
os_system_t system;

#define store_current_rsp() \
    __asm__ __volatile__( \
        "mov %rsp, system \r\n" \
    )

#define save_context() \
  __asm__ __volatile__( \
    "mov %rsp, %rbp \r\n" \
    "mov %rsp, system \r\n" \
    "push %rbp \r\n" \
    "push %rax \r\n" \
    "push %rbx \r\n" \
    "push %rcx \r\n" \
    "push %rdx \r\n" \
    "push %rdi \r\n" \
    "lea task_idle, %rax \r\n" \
    "movq %rbp, 0x0(%rax) \r\n" \
    "call set_task \r\n" \
  )

#define save_context2() \
  __asm__ __volatile__( \
    "mov %rbp, __stack__ \r\n" \
    "add $0x10, __stack__ \r\n" \
    "mov %rax, __stack__ \r\n" \
    "add $0x10, __stack__ \r\n" \
    "mov %rbx, __stack__ \r\n" \
    "add $0x10, __stack__ \r\n" \
    "mov %rcx, __stack__ \r\n" \
    "add $0x10, __stack__ \r\n" \
    "mov %rdx, __stack__ \r\n" \
    "add $0x10, __stack__ \r\n" \
    "mov %rdi, __stack__ \r\n" \
    "add $0x10, __stack__ \r\n" \
  )

__at task1_stack[STACK_SIZE];
__at task2_stack[STACK_SIZE];

void task1_proc() {}
void task2_proc() {}

// to jest źle
// Musi być lista zadań - kolejka zadań
// musi być funkcja która będzie to robiła,
// czyli dodawała zadania do klejki
// musi być mechanizm który będzie ustawiał status
// zadania z WAIT, na READY, na RUN
// Musi być mechanizm który będzie wywoływał zadania
// tzn zmieniał ich stan z jakiegoś powodu oraz
// musi też ustawiać po drodze status.
// Czyli to jest moment wywłaszczania zadania
// ale kiedy nie ma przełączania kontekstu, tylko
// ustawianie zadania w stan gotowości.
// To jest źle bo ciągle skaczę do task_idle
// trzeba wybierać zadanie właśnie w jakiś sposób.
// ech... lenistwo... 
void set_task()
{
  save_context();
  asm volatile(
    "mov $0, %rbx \r\n"
    "call task1_proc \r\n"
    "inc %rbx \r\n"
    "call task2_proc \r\n"
  );
}

void os_schedule()
{
    
}

void os_task_init(os_task_t *task, void *stack, __at stack_size, void *proc)
{
    //__at *_stack = stack + stack_size;
    __stack__ = stack;
    
    save_context2();
     
     
    TRAP
}

void os_task_create(os_task_t *task, void *stack, __at stack_size, void *proc)
{
    store_current_rsp();
    task->stack = stack;
    task->stack_size = stack_size;
    task->proc = proc;
    
    os_task_init(task, stack, stack_size, proc);
}

main()
{
  os_task_create(&task1, task1_stack, sizeof(task1_stack), task1_proc);
  os_task_create(&task2, task2_stack, sizeof(task2_stack), task2_proc);
  //save_context();
  while(1);
}
