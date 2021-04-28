#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	vector<pii>v;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.push_back({b, a});
	}
	sort(all(v));

	ll t = 0;
	bool ok = true;
	for(int i=0; ok and i<n; i++){
		int a = v[i].second;
		int b = v[i].first;
		if(t+a>b) ok = false;
		else t += a;
	}

	if(ok) cout << "Yes\n";
	else cout << "No\n";

	return 0;    
}


