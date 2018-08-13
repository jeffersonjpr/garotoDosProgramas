#include <stdio.h>
#include <string.h>

int main(){
    char b[100],c[100];
    int len;
    scanf("%[^\n]",b);
    len = strlen(b);
    b[len] = '\0';
    c[len] = '\0';
    printf("\n%s\n",b);
    for(int i = 0;i<len;i++){
        c[i] = b[len - i - 1];
    }
    printf("%s\n",c);

}
