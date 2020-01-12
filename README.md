#1
linux_ucontext - któryś kod wymaga kompilowania z flagą -lrt
gcc -g plik.c -o a.out -lrt

#2
rm -rf .git*
git init
git add .
git commit -m "test upload"
git remote add origin https://github.com/0xgoose/RTOS_Learn
git push -f origin master
