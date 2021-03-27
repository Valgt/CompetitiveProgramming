#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[55];

int get_max(priority_queue<int, vi, greater<int>>pq, int sum, int k){
	while(!pq.empty() and k>0){
		int x = pq.top();
		if(x >= 0) break;
		//cout << x << endl;
		sum -= x;
		k--;
		pq.pop();
	}
	//cout << endl;
	return sum;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;
	rep(i, 0, n) cin >> a[i];
	
	int ans = 0;
	for(int l=0; l<=n; l++){
		if(l>k) continue;
		for(int r=0; r<=n-l; r++){
			if(l+r > k) continue;
			priority_queue<int, vi, greater<int>>pq;
			int sum = 0;
			for(int i=0; i<l; i++){
				pq.push(a[i]);
				sum += a[i];
				//cout << a[i] << " ";
			}
			for(int i=0; i<r; i++){
				pq.push(a[n-1-i]);
				sum += a[n-1-i];
				//cout << a[n-1-i] << " ";
			}
			//cout << endl;
			ans = max(ans, get_max(pq, sum, k-l-r));
		}
	}
	cout << ans << endl;

	return 0;    
}


