#1<br>
linux_ucontext - któryś kod wymaga kompilowania z flagą -lrt<br>
gcc -g plik.c -o a.out -lrt<br>
<br>
#2<br>
rm -rf .git*<br>
git init<br>
git add .<br>
git commit -m "test upload"<br>
git remote add origin https://github.com/0xgoose/RTOS_Learn<br>
git push -f origin master<br>

#3 - Link do rados rtos<br>
https://github.com/rosly/rados

<br><br>
#4 - zrzut struktury task oraz zmiennej stack<br>
```c
:~/RTOS$ gdb -q a.out
Reading symbols from a.out...done.
(gdb) q
:~/RTOS$ cc -g main2.c
:~/RTOS$ gdb -q a.out
Reading symbols from a.out...done.
(gdb) run
Starting program: ../a.out 
^C
Program received signal SIGINT, Interrupt.
os_task_init (task=0x601b00 <task_1>, stats=0x601e30 <stats_1>, stack_param=0x601080 <stack_task1>, 
    t=0x4005c2 <task1>) at main2.c:132
132	    while(1);
(gdb) p task
$1 = (os_task_t *) 0x601b00 <task_1>
(gdb) p task_1
$2 = {ctx = {sp = 6295736}, ptr = 0x4005c2 <task1>, list = {0x4005c2 <task1>, 0x0 <repeats 99 times>}}
(gdb) p &task
$3 = (os_task_t **) 0x7fffffffdb98
(gdb) x/64wx 0x601b00
0x601b00 <task_1>:	0x006010b8	0x00000000	0x004005c2	0x00000000
0x601b10 <task_1+16>:	0x004005c2	0x00000000	0x00000000	0x00000000
0x601b20 <task_1+32>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b30 <task_1+48>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b40 <task_1+64>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b50 <task_1+80>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b60 <task_1+96>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b70 <task_1+112>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b80 <task_1+128>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601b90 <task_1+144>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601ba0 <task_1+160>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601bb0 <task_1+176>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601bc0 <task_1+192>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601bd0 <task_1+208>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601be0 <task_1+224>:	0x00000000	0x00000000	0x00000000	0x00000000
0x601bf0 <task_1+240>:	0x00000000	0x00000000	0x00000000	0x00000000
(gdb) i r
rax            0x601b00	6298368
rbx            0x0	0
rcx            0x4005c2	4195778
rdx            0x6010b8	6295736
rsi            0x601e30	6299184
rdi            0x601b00	6298368
rbp            0x7fffffffdbb0	0x7fffffffdbb0
rsp            0x7fffffffdbb0	0x7fffffffdbb0
r8             0x7ffff7dd4e80	140737351863936
r9             0x7ffff7dea600	140737351951872
r10            0x7fffffffdaf0	140737488345840
r11            0x7ffff7a32e50	140737348054608
r12            0x400400	4195328
r13            0x7fffffffdd40	140737488346432
r14            0x0	0
r15            0x0	0
rip            0x400554	0x400554 <os_task_init+43>
eflags         0x206	[ PF IF ]
cs             0x33	51
ss             0x2b	43
ds             0x0	0
es             0x0	0
fs             0x0	0
gs             0x0	0
(gdb) 
(gdb) p stack
$1 = (uint64_t *) 0x6010b8 <stack_task1+56>
```
