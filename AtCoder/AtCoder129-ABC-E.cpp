#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int mod = 1e9 + 7;
const int TAM = 1e5 + 100;
int n;
string s;
int p3[TAM];
int a[TAM];
int memo[TAM];
bool vis[TAM];

int rec(int pos){
	if(pos == 0){
		if(a[0] == 0) return 1;
		return 3;
	}
	if(a[pos] == 0) return rec(pos-1);
	return (1ll*p3[pos] + 2*rec(pos-1))%mod;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	p3[0] = 1;
	rep(i, 1, TAM) p3[i] = 1ll*3*p3[i-1] % mod;

	cin >> s;
	n = s.size();
	reverse(all(s));
	//cout << s << endl;
	rep(i, 0, n) a[i] = s[i] - '0';
	cout << rec(n-1) << endl;
	return 0;    
}


