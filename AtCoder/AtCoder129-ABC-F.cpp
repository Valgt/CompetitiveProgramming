#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll mod;
ll add(ll x, ll y){return (x%mod + y%mod + mod + mod)%mod;}
ll mult(ll x, ll y){return add(x, 0)*add(y, 0) % mod;}

vector<vector<ll> > mult_matrix(vector<vector<ll> >A,
		vector<vector<ll> >B){
	int n = A.size();
	int m = B[0].size();
	int p = B.size();
	vector<vector<ll> >ans(n, vector<ll>(m, 0));
	rep(i, 0, n){
		rep(j, 0, m){
			rep(k, 0, p) ans[i][j] = add(ans[i][j],
					mult(A[i][k], B[k][j]));
		}
	}
	return ans;
}

vector<vector<ll> >fast_expo(vector<vector<ll> >A, ll e){
	if(e == 1) return A;
	auto mid = fast_expo(A, e/2);
	auto ans = mult_matrix(mid, mid);
	if(e&1) ans = mult_matrix(ans, A);
	return ans;
}

ll l, a, b;
ll p10[25];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	cin >> l >> a >> b >> mod;
	p10[0] = 1;
	rep(i, 1, 19) p10[i] = 10LL*p10[i-1];
	//rep(i, 0, 19) cout << p10[i] << endl;

	vector<vector<ll> >p = {{0, a%mod, b%mod}};
	vector<vector<ll> >ans = {{1, 0, 0},{0, 1, 0},{0, 0, 1}};
	
	for(int d=1; d<=18; d++){
		ll L = (p10[d-1]-a+b-1)/b;
		//cout << "L: " << p10[d-1]-a+b-1 << endl;
		//cout << "R: " << p10[d]-1-a << endl;
		ll R = (p10[d]-a+b-1)/b;
		//printf("%d: %lld - %lld\n", d, L, R);
		L = min(l, max(0LL, L));
		R = max(min(l, R), 0LL);
		if(L == R) continue;
		//printf("%d -> %lld - %lld\n", d, L, R);
		vector<vector<ll> >pivot = {{p10[d]%mod, 0, 0},
									{1, 1, 0},
									{0, 1, 1}};
		ans = mult_matrix(ans, fast_expo(pivot, R-L));
		if(L >= l) break;
	}
	
	auto res = mult_matrix(p, ans);
	cout << res[0][0] << endl;

	return 0;    
}


