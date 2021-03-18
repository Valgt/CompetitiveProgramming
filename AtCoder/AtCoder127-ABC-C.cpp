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

int a[TAM];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	rep(i, 0, m){
		int l, r; cin >> l >> r;
		l--;
		a[l] += 1;
		a[r] -= 1;
	}
	int last = 0;
	int ans = 0;
	rep(i, 0, n){
		last += a[i];
		if(last == m) ans++;
	}
	cout << ans << endl;

	return 0;    
}


