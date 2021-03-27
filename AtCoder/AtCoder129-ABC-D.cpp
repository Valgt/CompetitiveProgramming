#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 2000 + 5;
string s[TAM];

int h[TAM][TAM];
int v[TAM][TAM];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	rep(i, 0, n) cin >> s[i];

	// Horizontal
	rep(i, 0, n){
		int last = 0;
		rep(j, 0, m){
			last = s[i][j]=='#' ? 0 : last+1;
			h[i][j] = last;
		}
		last = 0;
		for(int j=m-1; j>=0; j--){
			if(s[i][j] == '#') h[i][j] = 0;
			else h[i][j] = max(h[i][j], last);
			last = h[i][j];
		}
	}

	// Vertical
	rep(j, 0, m){
		int last = 0;
		rep(i, 0, n){
			last = s[i][j]=='#' ? 0 : last+1;
			v[i][j] = last;
		}
		last = 0;
		for(int i=n-1; i>=0; i--){
			if(s[i][j] == '#') v[i][j] = 0;
			else v[i][j] = max(v[i][j], last);
			last = v[i][j];
		}
	}

	int ans = 0;
	rep(i, 0, n){
		rep(j, 0, m){
			if(s[i][j] != '#') ans = max(ans, h[i][j] + v[i][j] - 1);
		}
	}
	cout << ans << endl;

	return 0;    
}


