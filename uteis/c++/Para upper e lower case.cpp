#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "Sapo De Botas";
    printf("%s\n",a.c_str());
    for(int i = 0; i<a.length();i++){
        printf("%c",toupper(a[i]));
    }
    printf("\n%s\n",a.c_str());
    for(int i = 0; i<a.length();i++){
        printf("%c",tolower(a[i]));
    }
    return 0;
}
