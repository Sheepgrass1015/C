#include <stdio.h>
int main(){
    char *s="hello";
    printf("%c\n",*s);
    *s="world";
    printf("%c\n",*s);
}