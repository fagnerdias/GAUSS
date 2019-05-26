lex gauss.l
bison -d -v gauss.y
g++ gauss.tab.c lex.yy.c -o sintatico.exe
echo "\n\n\n\n"
./sintatico.exe < exemplo.txt