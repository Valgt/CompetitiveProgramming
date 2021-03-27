#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 1e5 + 100;
int mod = 1e9 + 7;
int n;
int f[TAM];
ll dp[TAM];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int m;
	cin >> n >> m;
	rep(i, 0, m){
		int x; cin >> x;
		f[x] = 1;
	}

	dp[0] = 1;
	rep(i, 1, n+1){
		if(i-1>=0 and f[i-1]!=1) dp[i] = (dp[i] + dp[i-1])%mod;
		if(i-2>=0 and f[i-2]!=1) dp[i] = (dp[i] + dp[i-2])%mod;
	}
	cout << dp[n] << endl;

	return 0;    
}


