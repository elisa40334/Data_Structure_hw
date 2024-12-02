#include<iostream>
#include<stdarg.h>
#include<string.h>

typedef struct data {
	int value;
	char a[500];
} data_t;

void myprintf(void *first, ...){

    data_t str;
    data_t data1;
	data1.value = (int)first;
	strcpy(data1.a, (char*)first);
    int a;
    va_list ap;
    str.(a) =  (*first);
    //  str = (char)(*first);
     va_start(ap, first);               // 開始使用 va_list
     do {
        fputs(str,stdout);
        str = va_arg(ap, char*);    // 指向下一個參數
     } while(str != NULL);
     va_end(ap); 
}

int main(){
    myprintf("string test: %s\n", "123456");
}

