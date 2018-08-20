#include <stdio.h>

int main()
{
    int i=3, j=5;
    int *p, *q;
    p= &i;
    q= &j;

    if (p == &i) printf("verdadeiro\n");
    printf("%i\n",*p -*q);
    printf("%i\n",3*-*p/(*q-2));
}
