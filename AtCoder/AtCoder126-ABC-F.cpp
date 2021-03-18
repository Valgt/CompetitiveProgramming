#include<bits/stdc++.h>

using namespace std;

/*
	Author: Sergio Sanchez
	Idea:
	- Math
	- (4*k) xor (4*k+1) xor (4*k+2) xor (4*k+3) = 0
	- z = 2^m, the pattern is k 0 1 ... z k z (z-1) ... 0
	- Complexity: O(n^2)
*/

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

	int n, k;
	cin >> n >> k;

	if(n==0){
		if(k==0) cout << "0 0\n";
		else cout << "-1\n";
		return 0;
	}
	if(n==1){
		if(k==0) cout << "0 0 1 1\n";
		else cout << "-1\n";
		return 0;
	}
	if(k >= (1<<n)){
		cout << "-1\n";
		return 0;
	}

	cout << k;
	for(int i=0; i<(1<<n); i++){
		if(i != k) cout << " " << i;
	}
	cout << " " << k;
	for(int i=(1<<n)-1; i>=0; i--){
		if(i != k) cout << " " << i;
	}
	cout << endl;

	return 0;    
}


