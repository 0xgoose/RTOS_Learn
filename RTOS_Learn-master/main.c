#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint64_t sp;    
    uint64_t spNegate;
    int counter;
} os_system_t;

os_system_t system;
os_system_t *os;

int main()
{
    os = &system;
    os->sp |= 0xfa;
    os->spNegate = ~os->sp;
    
    while((os->counter++) < 10) {
        printf("%llu %llu \n", (long long unsigned int)os->sp, (long long unsigned int)os->spNegate);
        sleep(1);
    }
  return 0;
}
