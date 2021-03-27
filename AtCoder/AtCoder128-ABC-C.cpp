#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<int>d[15];
int p[15];
int a[15];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m;
	rep(i, 0, m){
		int k; cin >> k;
		rep(j, 0, k){
			int v; cin >> v;
			d[i].push_back(v-1);
		}
	}
	rep(i, 0, m) cin >> p[i];

	int ans = 0;
	rep(mask, 0, (1<<n)){
		rep(i, 0, n) a[i] = (mask>>i)&1;
		//cout << "##\n";
		//rep(i, 0, n) cout << a[i] << " "; cout << endl;
		int mask2 = 0;
		rep(i, 0, m){
			int sum = 0;
			trav(pos, d[i]) sum += a[pos];
			//cout << sum << " ";
			mask2 += (1<<i)*(p[i] == sum%2);
		}
		//cout << endl;
		ans += (mask2+1 == (1<<m));
	}
	cout << ans << endl;
	return 0;    
}


