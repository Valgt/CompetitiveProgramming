#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 100000 + 100;
vector<pii> G[TAM];
int h[TAM];

void dfs(int u, int pd=-1, int rh=0){
	h[u] = rh;
	trav(p, G[u]){
		if(pd == p.first) continue;
		dfs(p.first, u, rh + p.second);
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	for(int i=0; i<n-1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--; w&=1;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(0);

	for(int i=0; i<n; i++) cout << (h[i]&1) << endl;

	return 0;    
}


