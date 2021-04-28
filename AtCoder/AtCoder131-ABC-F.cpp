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

vi xg[TAM];
vi yg[TAM];
bool xb[TAM];
bool yb[TAM];

pair<pii, int> dfs(int p, int flag){
	//cout << p << " " << flag << endl;
	if(flag == 0){
		// X
		pair<pii, int> ans = {{1, 0}, xg[p].size()};
		xb[p] = true;
		trav(y, xg[p]){
			if(yb[y]) continue;
			auto partial = dfs(y, 1);
			ans.first.first += partial.first.first;
			ans.first.second += partial.first.second;
			ans.second += partial.second;
		}
		return ans;
	}
	else{
		// Y
		pair<pii, int> ans = {{0, 1}, yg[p].size()};
		yb[p] = true;
		trav(x, yg[p]){
			if(xb[x]) continue;
			auto partial = dfs(x, 0);
			ans.first.first += partial.first.first;
			ans.first.second += partial.first.second;
			ans.second += partial.second;
		}
		return ans;
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	rep(i, 0, n){
		int x, y;
		cin >> x >> y;
		xg[x].push_back(y);
		yg[y].push_back(x);
	}

	ll ans = 0;
	for(int x=1; x<=100000; x++){
		if(xb[x]) continue;
		auto p = dfs(x, 0);
		//if(p.second) cout << p.first.first << " " << p.first.second << " " << p.second << endl;
		ans += 1ll*p.first.first*p.first.second - p.second/2;
	}
	cout << ans << endl;
	return 0;    
}


