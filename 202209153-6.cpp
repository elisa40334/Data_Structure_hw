#include<stdio.h>
#include<math.h>
#include <limits.h>
#include<stdarg.h>
void myprintf(const char* fmt, ...){
    va_list args;
    va_start(args, fmt);
 
    while (*fmt != '\0') {
        if (*fmt == '%')
        {
            if (*(fmt+1) == 'd') {
                int i = va_arg(args, int),cal = 0,abc;
                char a;
                if (i < 0)
                {
                    fputc('-',stdout);
                }
                if(i < 0) i = -i;
                if (i >= 1000000000)
                {
                    abc = 1000000000;
                    for ( ; i%abc >= 0 && abc > 1; abc /= 10)
                    {
                        int x = i/abc;
                        fputc('0'+x,stdout);
                        i %= abc;
                    }
                    fputc('0'+i,stdout);
                }
                else
                {
                    for (abc = 10; abc <= i; abc *= 10){}
                    for (abc/=10 ; i%abc >= 0 && abc > 1; abc /= 10)
                    {
                        int x = i/abc;
                        fputc('0'+x,stdout);
                        i %= abc;
                    }
                    if (i == 0)
                    {
                        fputc('0',stdout);
                    }
                    else
                    {
                        fputc('0'+i,stdout);
                    }
                    
                }
                 ++fmt;
            } else if (*(fmt+1) == 'c') {
                int c = va_arg(args, int);
                fputc(c,stdout);
                ++fmt;
            } else if (*(fmt+1) == 's') {
                char* s = va_arg(args,char*);
                fputs(s,stdout);
                ++fmt;
            }
            else if (*(fmt+1) == '%') {
                fputs("%",stdout);
                ++fmt;
            }
        } 
        else fputc(*fmt,stdout);
        ++fmt;
    }
    va_end(args);
    return;
}

int main(){
    myprintf("string test: %s\n", "123456");
    myprintf("int max: %d\n", INT_MAX);
    myprintf("int negative: %d\n", 0);
    myprintf("char %c %c %c \n", 'a', 'b', 'c');
    myprintf("mixed: %c %s %d \n", 'a', "abc", 1234);

}



