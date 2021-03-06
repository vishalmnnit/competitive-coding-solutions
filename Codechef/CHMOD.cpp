#include<iostream>
#define endl '\n'

using namespace std;

typedef unsigned long long ll;

ll fast_exp(ll base, ll exp, ll MOD) {
    ll res=1;
    while(exp|0) {
       if(exp&1)
	   res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp = exp>>1;
    }
    return res;
}

ll CF[100001][25]={0};
int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int N,T,L,R,M,A;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll answer(1);
	cin >> N;
	for(int i=1;i<=N;++i){
		cin >> A;
		for(int j=0;j<25;++j){
			int p = primes[j];
			CF[i][j] = CF[i-1][j];
			while(A%p==0){ ++CF[i][j]; A/=p; }
		}
	}
	
	cin >> T;
	
	while(T--){
		answer = 1;
		cin >> L >> R >> M;
		for(int j=0;j<25;++j){
			answer = ( answer * fast_exp( primes[j], CF[R][j] - CF[L-1][j], M) )% M;
		}
		cout << answer << endl;
	}
	return 0;
}
