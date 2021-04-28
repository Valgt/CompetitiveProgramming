#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll c, d, cd;

ll f(ll x){
	ll ans = x/c + x/d - x/cd;
	return ans;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll a, b;
	cin >> a >> b >> c >> d;
	cd = 1ll*c*d/__gcd(c, d);
	//cout << c << " " << d << " " << cd << endl;
	cout << b-a+1 - f(b) + f(a-1) << endl;
	return 0;    
}


