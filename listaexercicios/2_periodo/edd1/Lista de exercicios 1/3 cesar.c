#include <stdio.h>
#include <string.h>

short int encripta(short int n){
    if(n == 32) return 32;
    if(n>=120){
        if(n == 120) return 97;
        if(n == 121) return 98;
        if(n == 122) return 99;
    }
    return n + 3;
}

int main(){
    char pano[1024];
    printf("Digite uma palavra :");
    fflush(stdin);
    gets(pano);
    printf("%s\n",pano);
    printf("Encripitado : \n");
    for(int i = 0;i < strlen(pano);i++){
        printf("%c",encripta(pano[i]));
    }
}
