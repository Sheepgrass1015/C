#include <stdio.h>
int main(){
    int i;
    int j;
    double d;
    int a[10];
    printf("%p\n",&i);
    printf("%p\n",&j);
    printf("%p\n",&d);
    printf("%lu\n",sizeof(&i));
    printf("%lu\n",sizeof(&j));
    printf("%p\n",&a);
    printf("%p\n",a);
    printf("%p\n",&a[0]);
    printf("%p\n",&a[1]);
}