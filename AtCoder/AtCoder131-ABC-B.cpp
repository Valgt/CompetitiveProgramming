#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[1005];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, l; cin >> n >> l;
	int s = 0;
	rep(i, 0, n){
		a[i] = l+i;
		s += a[i];
	}

	int x = INT_MAX/2;
	rep(i, 0, n){
		if(abs(x) > abs(a[i])){
			x = a[i];
		}
	}
	cout << s - x << endl;

	return 0;    
}


