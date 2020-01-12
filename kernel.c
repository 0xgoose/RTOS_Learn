#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint64_t ctx;
} os_context_t;

typedef struct {
    uint64_t base_rsp;
    uint64_t current_rsp;
    uint64_t isr_rsp;
    uint64_t current_task;
} os_base_t;

typedef struct {
    int a;
    int b;
    int c;
    volatile int x;
    uint32_t code;
} os_system_t;

os_system_t t;
os_system_t *os;

os_base_t bt;
os_base_t *ob;

void task2();
void context_switch();

#define context_store() \
    asm volatile( \
        "mov bt, %r14 \n\t" \
        "lea bt, %r15 \n\t" \
        "movq %rsp, 0x8(%r15) \n\t" \
        "subq $0xbb8, %r14 \n\t" \
        "mov %r14, %rsp \n\t" \
        "push %rax \n\t" \
        "push %rbx \n\t" \
        "push %rcx \n\t" \
        "push %rdx \n\t" \
        "push %rsi \n\t" \
        "push %rdi \n\t" \
        "push %rbp \n\t" \
        "push %r8 \n\t" \
        "push %r9 \n\t" \
        "push %r10 \n\t" \
        "push %r11 \n\t" \
        "push %r12 \n\t" \
        "push %r13 \n\t" \
        "push %r14 \n\t" \
        "push %r15 \n\t" \
        "addq $0xbb8, %r14 \n\t" \
        "mov 0x8(%r15), %rsp \n\t" \
    )

#define jump_to_task2() \
    asm volatile( \
        "lea task2, %r14 \n\t" \
        "call *%r14 \n\t" \
    )

#define context_switch() \
    asm volatile( \
        "context_switch_label:          \n\t" \
        "mov counter, %r15              \n\t" \
        "lea task1, %r14                \n\t" \
        "cmp $2, %r15                   \n\t" \
        "jne jump_to_task2              \n\t" \
        "ja end                         \n\t" \
        "call *%r14                     \n\t" \
        "jump_to_task2:                 \n\t" \
        "lea task2, %r14                \n\t" \
        "call *%r14                     \n\t" \
        "end:                           \n\t" \
        "jmp context_switch_label       \n\t" \
    )

#define save_base_rsp() \
    asm volatile( \
        "movq %rsp, bt \n\t" \
    )



volatile sig_atomic_t print_flag = false;

volatile int t1, counter, state, state2;



void task1() 
{
    state++;
    //asm volatile ("ret");
}

void task2() 
{
    /*
    t1=0;
    //asm volatile ("ret");
    asm volatile(
        "lea t, %ebx \n"
        "mov 0x10(%ebx), %ecx \n"
        "sub $(1 << 5), %ecx \n"
        "mov %ecx, 0x10(%ebx) \n"
        "mov 0x10(%ebx), %eax \n"
   ); 
   */
   state2++;
   //counter=0;
}




void handle_alarm( int sig ) {
    
    /*
    if (t1 > 2) {
        asm volatile ("call task2");   
    } else {
    asm volatile ("call task1");
    }*/
    //context_store();
    context_store();
    context_switch();
    print_flag = true;
    t1++;
    //printf( "Hello %d\n", t1 );
}

static void my_signal_interrupt(int sig)
{
  //printf("I got signal %d\n", sig);
  //(void) signal(SIGINT, SIG_IGN);
  //asm volatile ("call task2");  
  
}



int main()
{
    save_base_rsp();
   os = &t;
   ob = &bt;
   
   
   os->code = 0xffffffff;
   /*
   asm volatile(
        "lea t, %ebx \n"
        "mov 0x10(%ebx), %ecx \n"
        "sub $(1 << 5), %ecx \n"
        "mov %ecx, 0x10(%ebx) \n"
        "mov 0x10(%ebx), %eax \n"
   );
   */ 
   //asm volatile("mov %ecx, %ebx");
   
  (void) signal( SIGALRM, handle_alarm ); // Install handler first,
  alarm( 1 );
  (void) signal(SIGINT, my_signal_interrupt); // CTRL + C

  while(1) {
        if ( print_flag ) {
        print_flag = false;
            alarm( 1 );
            counter++;
        }
      //printf("Waiting for interruption...\n");
      sleep(1);
  }
}

