#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int toInt(char d, char u){
	return 10*(d-'0') + (u-'0');
}
int canBeMonth(int x){
	return x>=1 and x<=12;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	string s;
	cin >> s;
	int flag = 0;
	if( canBeMonth(toInt(s[0], s[1])) ) flag += 1;
	if( canBeMonth(toInt(s[2], s[3])) ) flag += 2;

	string r;
	if(flag==0) r = "NA";
	else if(flag==1) r = "MMYY";
	else if(flag==2) r = "YYMM";
	else r = "AMBIGUOUS";

	cout << r << endl;

	return 0;    
}


