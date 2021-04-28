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
vector<ll>a;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	ll k;
	cin >> n >> k;
	a.push_back(0);
	rep(i, 1, n+1){
		int y; cin >> y;
		a.push_back(a.back() + y);
	}

	ll ans = 0;
	rep(i, 1, n+1){
		int lower = lower_bound(all(a), k+a[i-1]) - a.begin();
		//cout << n-lower+1 << endl;
		ans += n-lower+1;
	}
	cout << ans << endl;

	return 0;    
}


