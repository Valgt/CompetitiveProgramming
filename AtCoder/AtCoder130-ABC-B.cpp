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

	int n, x; cin >> n >> x;
	int last = 0;
	int ans = 1;
	rep(i, 0, n){
		int y;
		cin >> y;
		last += y;
		if(last <= x) ans++;
	}
	cout << ans << endl;
	return 0;    
}


