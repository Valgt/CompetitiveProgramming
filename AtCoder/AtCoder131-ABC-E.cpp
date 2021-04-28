#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t[105][105];

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	int ma = ((n-1)*(n-2))/2;
	if(k > ma){
		cout << "-1\n";
		return 0;
	}

	int cont = n-1;
	for(int i=1; i<n; i++) t[0][i] = 1;
	int q = ma - k;
	for(int i=1; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(q>0){
				t[i][j] = 1;
				q--;
				cont++;
			}
		}
	}

	cout << cont << endl;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(t[i][j]) cout << i+1 << " " << j+1 << endl;
		}
	}

	return 0;    
}


