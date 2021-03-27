#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 2e5 + 100;

int n, q;
vi in[TAM];
vi out[TAM];

int ans[TAM];
int s[TAM];
int t[TAM];
int x[TAM];
vi d;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n >> q;
	for(int i=0; i<n; i++) cin >> s[i] >> t[i] >> x[i];
	for(int i=0; i<q; i++){
		int y; cin >> y;
		d.push_back(y);
	}

	for(int i=0; i<n; i++){
		int l = s[i] - x[i];
		int r = t[i] - 1 - x[i];
		if(r < d[0] or l > d.back()) continue;
		l = max(l, d[0]);
		r = min(r, d.back());

		//printf("[%d - %d]\n", l, r);
		int lower = lower_bound(all(d), l) - d.begin();
		int upper = upper_bound(all(d), r) - d.begin();
		//cout << lower << " " << upper << endl;
		if(lower >= upper) continue;
		in[lower].push_back(x[i]);
		out[upper-1].push_back(x[i]);
	}

	multiset<int>ms;
	for(int i=0; i<d.size(); i++){
		trav(y, in[i]) ms.insert(y);
		if(ms.size() == 0) ans[i] = -1;
		else ans[i] = *ms.begin();
		trav(y, out[i]) ms.erase(ms.find(y));
	}
	rep(i, 0, q) cout << ans[i] << endl;

	return 0;    
}


