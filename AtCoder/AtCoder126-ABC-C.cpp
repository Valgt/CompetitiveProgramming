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
	
	int n, k;
	cin >> n >> k;
	long double ans = 0;
	for(int score=1; score<=n; score++){
		long double partial = 1.0L/n;
		int sc = score;
		while(sc<k){
			sc *= 2;
			partial /= 2;
		}
		ans += partial;
	}
	cout << fixed << setprecision(12);
	cout << ans << endl;
	return 0;    
}


