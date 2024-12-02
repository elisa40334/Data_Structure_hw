#include <stdio.h>
#include <string.h>
typedef struct data {
	int value;
	char a[20];
} data_t;

void func(void *void_ptr)
{
    data_t *data1 = (data_t *)void_ptr;
    strcpy(data1.a, *void_ptr);

	//printf("%d\n", data1->value);
	printf("%s\n", data1->a);
}

int main(int argc, char* argvp[])
{
    
	int b = 23;
    //printf("%s\n", a);
	func(&b);

    return 0;
}