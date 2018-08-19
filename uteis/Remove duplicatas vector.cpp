#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a;
    a.push_back(20);
    a.push_back(10);
    a.push_back(1);
    a.push_back(20);
    a.push_back(10);
    a.push_back(1);

    sort(a.begin(),a.end());
    for(int i =0;i < a.size();i++){
        printf("%i\n",a[i]);
    }
    printf("\n");
    a.erase(unique(a.begin(),a.end()),a.end()); // <<<< remove as duplicatas
    for(int i =0;i < a.size();i++){
        printf("%i\n",a[i]);
    }
}
