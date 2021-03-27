#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int TAM = 1e5 + 100;

int n;
int s[TAM];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> n;
	for(int i=0; i<n; i++) cin >> s[i];

	ll ans = LLONG_MIN;
	for(int c=1; c<=n-1; c++){
		//printf("\nC=%d\n", c);
		if( (n-1)%c == 0 ){
			ll acum = 0;
			int l = 0;
			int r = n-1;
			for(int k=0; l<r; k++){
				//cout << l << " " << r << ": ";
				acum += s[l];
				acum += s[r];
				//cout << acum << endl;
				l += c;
				r -= c;
				ans = max(ans, acum);
			}
		}
		else{
			int l = 0;
			int r = n-1;
			ll acum = 0;
			for(int k=0; k<(n-1)/c; k++){
				//cout << l << " " << r << ": "; 
				acum += s[l];
				acum += s[r];
				//cout << acum << endl;
				l += c,
				r -= c;
				ans = max(ans, acum);
			}
		}
	}
	cout << ans << endl;
	return 0;    
}


