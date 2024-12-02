#include<stdio.h>
#include<stdarg.h>
void printLine(char* first, ...){
     char*str;
     va_list ap;
     
     str = first;
     va_start(ap, first);               // 開始使用 va_list
     do {
         printf("%s \n", str);
         str = va_arg(ap, char*);    // 指向下一個參數
     } while(str != NULL);
     va_end(ap);                    // 停止使用
 }

int main(){

    printLine("first", "second", "third", "fourth", "fifth");
    return 0;
}
