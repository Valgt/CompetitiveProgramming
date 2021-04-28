#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int TAM = 1e5 + 100;

int n;
int x[TAM];
int y[TAM];
char c[TAM];

long double get_x_dist(long double time){
	long double mx = -DBL_MAX;
	long double mn = DBL_MAX;
	for(int i=0; i<n; i++){
		long double xt = x[i];
		if(c[i] == 'L') xt -= time;
		if(c[i] == 'R') xt += time;
		mx = max(mx, xt);
		mn = min(mn, xt);
	}
	return mx-mn;
}

long double get_y_dist(long double time){
	long double mx = -DBL_MAX;
	long double mn = DBL_MAX;
	for(int i=0; i<n; i++){
		long double yt = y[i];
		if(c[i] == 'D') yt -= time;
		if(c[i] == 'U') yt += time;
		mx = max(mx, yt);
		mn = min(mn, yt);
	}
	return mx-mn;
}

long double get_area(long double time){
	//cout << get_x_dist(time) << endl;
	//cout << get_y_dist(time) << endl;
	return get_x_dist(time)*get_y_dist(time);
}

int main(){
	cin.exceptions(cin.failbit);

	int inf = 1e8 + 10;
	ld l_max = -inf, l_min = inf;
	ld r_max = -inf, r_min = inf;
	ld u_max = -inf, u_min = inf;
	ld d_max = -inf, d_min = inf;
	ld x_max = -inf, x_min = inf;
	ld y_max = -inf, y_min = inf;

	set<ld>s;
	s.insert(0);

	cin >> n;
	rep(i, 0, n){
		cin >> x[i] >> y[i] >> c[i];
		if(c[i] == 'R'){
			r_max = max(r_max, (ld)x[i]);
			r_min = min(r_min, (ld)x[i]);
			y_min = min(y_min, (ld)y[i]);
			y_max = max(y_max, (ld)y[i]);
		}
		if(c[i] == 'L'){
			l_max = max(l_max, (ld)x[i]);
			l_min = min(l_min, (ld)x[i]);
			y_min = min(y_min, (ld)y[i]);
			y_max = max(y_max, (ld)y[i]);
		}
		if(c[i] == 'U'){
			u_max = max(u_max, (ld)y[i]);
			u_min = min(u_min, (ld)y[i]);
			x_min = min(x_min, (ld)x[i]);
			x_max = max(x_max, (ld)x[i]);
		}
		if(c[i] == 'D'){
			d_max = max(d_max, (ld)y[i]);
			d_min = min(d_min, (ld)y[i]);
			x_min = min(x_min, (ld)x[i]);
			x_max = max(x_max, (ld)x[i]);
		}
	}

	ld p;
	// X_MAX
	// - -> +
	p = max(0.0L, (l_max - r_max)/2);
	s.insert(p);
	// - -> =
	p = max(0.0L, l_max - x_max);
	s.insert(p);
	// = -> +
	p = max(0.0L, x_max - r_max);
	s.insert(p);
	
	// Y_MAX
	// - -> +
	p = max(0.0L, (d_max - u_max)/2);
	s.insert(p);
	// - -> =
	p = max(0.0L, d_max - y_max);
	s.insert(p);
	// = -> +
	p = max(0.0L, y_max - u_max);
	s.insert(p);

	// X_MIN
	// + -> -
	p = max(0.0L, (l_min - r_min)/2);
	s.insert(p);
	// + -> =
	p = max(0.0L, x_min - r_min);
	s.insert(p);
	// = -> -
	p = max(0.0L, l_min - x_min);
	s.insert(p);

	// Y_MIN
	// + -> -
	p = max(0.0L, (d_min - u_min)/2);
	s.insert(p);
	// + -> =
	p = max(0.0L, y_min - u_min);
	s.insert(p);
	// = -> -
	p = max(0.0L, d_min - y_min);
	s.insert(p);

	ld ans = DBL_MAX;
	trav(time, s){
		cout << setprecision(10) << fixed;
		//cout << time << " " << get_area(time) << endl;
		ans = min(ans, get_area(time));
	}
	cout << setprecision(10) << fixed << ans << endl;
	return 0;    
}


