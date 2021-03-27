#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Res{
	string name;
	int index, score;
};

bool operator<(const Res&a, const Res&b){
	if(a.name != b.name) return a.name < b.name;
	return a.score > b.score;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n; cin >> n;
	vector<Res>v;

	rep(i, 0, n){
		string s;
		int score;
		cin >> s >> score;
		v.push_back( Res({s, i+1, score}) );
	}
	sort(all(v));
	trav(res, v) cout << res.index << endl;

	return 0;    
}


