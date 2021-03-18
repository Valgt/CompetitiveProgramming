#include<bits/stdc++.h>

using namespace std;

/*
	Author: Sergio Sanchez
	Idea:
	- Math
	- x and y can be separated
	- Two points that are at a distance d on the x-axis contribute that Comb (n * m-2, k-2) times and the number of points that are at a distance d are (n-d) * m * m
	- For x, do the same calculation swaping x and y
	- Complexity: O(nm)
*/


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 2e5 + 10;
ll mod = 1e9 + 7;
ll add(ll x, ll y){return (x+y+2*mod)%mod;}
ll mult(ll x, ll y){return add(x, 0)*add(y, 0)%mod;}
ll fast_expo(ll x, ll y){
	if(y==0) return 1;
	ll mid = fast_expo(x, y/2);
	ll ans = y&1 ? x : 1;
	return mult(ans, mult(mid, mid));
}
ll inver(ll x){return fast_expo(x, mod-2);}

// Return Comb(n*m-2, k-2)
ll get_factor(int n, int m, int k){
	ll num = 1, den = 1;
	for(int i=0; i<k-2; i++){
		num = mult(num, n*m-2-i);
		den = mult(den, k-2-i);
	}
	return mult(num, inver(den));
}

ll solve(int n, int m, int k){
	ll acum = 0;
	for(int d=1; d<=n-1; d++){
		acum = add(acum, mult(mult(d, n-d), mult(m, m)));
	}
	return mult(acum, get_factor(n, m, k));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n, m, k;
	cin >> n >> m >> k;
	cout << add(solve(n, m, k),	solve(m, n, k)) << endl;
	return 0;    
}


