#include <bits/stdc++.h>
using namespace std;


string convertebin(long long a){
	string ba("00000000000000000000000000000000");
	int cont = 31;
	long long n;
	for(long long i = 0; cont >= 0; cont--,i++){
		n = pow(2,cont);
		if(n <= a){
			ba[i] = '1';
			a -= n;
		}
	}
	return ba;
}
