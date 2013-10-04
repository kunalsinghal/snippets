#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define cin(n) scanf("%d",&n)
#define gc getchar_unlocked
typedef vector<int> VI;
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}
const int maxn = (int)1e7 + 10;

int num[10000001]; 
int i,j,temp;
void sieve(){
	for(i=2;i<=3162;i++){ 
		if(!num[i])for(j = i*i;j<10000001;j+=i){
			num[j] = i; 
		}
	}
}
int phi[10000001]= {0,1,1,2,2,4};
long long arr[10000001] = {0,0,3};
int main(){
	sieve();
	for(i=6;i<=10000000;i++){
		if(!num[i])phi[i] = i-1;
		else {
			temp = i/num[i]; 
			if(temp % num[i] == 0){
				phi[i] = phi[temp] * num[i];
			} else {
				phi[i] = phi[temp] * (num[i]-1);
			}
		}
	}
	for(i=3;i<=10000000;i++){
		arr[i] = arr[i-1] + (phi[i-1]<<1); 
	}
	int tests=fcin();
	while(tests--){
		printf("%lld\n",arr[fcin()]); 
	}
}