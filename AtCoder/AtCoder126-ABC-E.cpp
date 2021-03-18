#include<bits/stdc++.h>

using namespace std;

/*
	Author: Sergio Sanchez
	Idea:
	- Data structures
	- Each A_{i} is a node and each (x_{j}, y_{j}, z_{j}) creates an edge, knowing the value of a node the value of the other nodes of its component can be deduced.
	- Complexity: O(\alpha(n))
 */

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	UF uf = UF(n);
	for(int i=0; i<m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		uf.join(x, y);
	}
	int ans = 0;
	rep(i, 0, n){
		if(uf.e[i] < 0) ans++;
	}
	cout << ans << endl;
	return 0;    
}


