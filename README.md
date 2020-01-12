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
