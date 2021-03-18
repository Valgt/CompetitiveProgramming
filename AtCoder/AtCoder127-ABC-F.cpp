#include<bits/stdc++.h>

using namespace std;

/*
	Author: Sergio Sanchez
	Idea:
	- Data structures
	- Find the minimum f(x) = sum( |a_{i} - x| + b_{i})
	- b_{i} is independet of x
	- Find the minimum f(x) = sum(|a_{i} - x|) dynamically is a classic problem, it is necessary to know the median
	- Complexity: O(n log n)
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
multiset<int>L, R;
ll sumL, sumR;

void balance(){
	while( L.size()<R.size() or L.size()>R.size()+1 ){ 
		if(L.size()>R.size()+1){
			int value = *L.rbegin();
			sumR += value;
			R.insert(value);
			sumL -= value;
			L.erase(L.find(value));
		}
		else{
			int value = *R.begin();
			sumR -= value;
			L.insert(value);
			sumL += value;
			R.erase(R.find(value));
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll offset = 0;
	cin >> n;
	while(n--){
		int a, b, op;
		cin >> op;
		if(op == 1){
			cin >> a >> b;
			offset += b;
			if(L.size() == 0 and R.size() == 0){
				L.insert(a);
				sumL += a;
			}
			else if(*L.rbegin() >= a ){
				L.insert(a);
				sumL += a;
			}
			else{
				R.insert(a);
				sumR += a;
			}
			balance();
		}
		else{
			ll value = *L.rbegin();
			ll ans = sumR - value*R.size();
			ans += value*L.size() - sumL;
			cout << value << " " << ans + offset << endl;
		}
	}
	return 0;    
}


