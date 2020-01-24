/*
 * Więc są rejestry...
 * RIP => steruje instrukcją call
 * RSP => wskaźnik stosu
 */

typedef struct {
  long long int ctx;
} os_context_t;

typedef struct {
  os_context_t context;
  void *param;
} os_task_t;

// dodaj struktury dla zadań
// pierwsze zadanie to task_idle
os_task_t task_idle, task1_t, task2_t;

#define save_context() \
  __asm__ __volatile__( \
    "mov %rsp, %rbp \r\n" \
    "push %rbp \r\n" \
    "push %rax \r\n" \
    "push %rbx \r\n" \
    "push %rcx \r\n" \
    "push %rdx \r\n" \
    "lea task_idle, %rax \r\n" \
    "movq %rbp, 0x0(%rax) \r\n" \
    "call set_task \r\n" \
  )

long long int volatile current_task;

void task1() {}
void task2() {}

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
    "call task1 \r\n"
    "inc %rbx \r\n"
    "call task2 \r\n"
  );
}

main()
{
  save_context();
  while(1);
}
