#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<int, int>total;
set<pii>s;

vector<pii>v;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	rep(i, 0, n){
		int a; cin >> a;
		v.push_back({a, 1});
	}
	rep(i, 0, m){
		int b, c;
		cin >> b >> c;
		v.push_back({c, b});
	}
	sort(all(v));
	reverse(all(v));

	ll ans = 0;
	trav(p, v){
		int value = p.first;
		int cont = p.second;
		int take = min(cont, n);
		n -= take;
		ans += 1ll*take*value;
	}
	cout << ans << endl;
	/*
	int n, m;
	cin >> n >> m;
	rep(i, 0, n){
		int a; cin >> a;
		total[a] += 1;
	}
	trav(p, total){
		s.insert(p);
	}
	rep(i, 0, m){
		int cont, value;
		cin >> cont >> value;
		while(s.begin()->first < value and cont > 0){	
			int old_value = s.begin()->first;
			int old_cont = s.begin()->second;
			s.erase({old_value, old_cont});
		}
	}
	*/
	return 0;    
}


