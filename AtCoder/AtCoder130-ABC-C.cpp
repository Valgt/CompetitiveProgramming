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

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	long double area = 1.0L*n*m / 2;
	cout << setprecision(10) << fixed << area << " ";

	if( (n%2==0 and n/2==x) and (m%2==0 and m/2==y) ) cout << "1";
	else cout << "0";
	cout << endl;

	return 0;    
}


