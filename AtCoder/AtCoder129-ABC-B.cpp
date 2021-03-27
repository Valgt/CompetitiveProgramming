#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[105];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	int sum =0 ;
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum += a[i];
	}
	int acum = 0;
	int ans = INT_MAX;
	for(int i=0; i<n-1; i++){
		acum += a[i];
		ans = min(ans, abs( sum - 2*acum ));
	}
	cout << ans << endl;

	return 0;    
}


