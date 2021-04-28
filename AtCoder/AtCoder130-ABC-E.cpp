#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 2005;
int mod = 1e9 + 7;
int n, m;

int a[TAM];
int b[TAM];
bool vis[TAM][TAM];
ll memo[TAM][TAM];

ll dp(int i, int j){
	if(i==n or j==m) return 1;
	if(vis[i][j]) return memo[i][j];
	vis[i][j] = 1;
	ll ans = 0;
	ans = (ans + dp(i, j+1))%mod;
	ans = (ans + dp(i+1, j))%mod;
	ans = (ans - dp(i+1, j+1) + mod)%mod;
	if(a[i] == b[j]) ans = (ans + dp(i+1, j+1))%mod;
	return memo[i][j] = ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	
	/*
	for(int i=0; i<=n; i++) memo[i][0] = 1;
	for(int i=0; i<=m; i++) memo[0][i] = 1;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			
		}
	}
	*/
	cout << dp(0, 0) << endl;
	return 0;    
}


