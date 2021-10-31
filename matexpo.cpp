#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,pii> ppi;
typedef pair<pii,pii> ppp;
#define FOR(i, n) for(LL i = 1; i<=n; i++)
#define F0R(i, n) for(LL i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {cout << "["; F0R(i, v.size()) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
 
//var 
const LL MOD = 1e9 + 7;
LL T, n, m, k;
 
vector<vector<LL>> identity(LL g){
	vector<vector<LL>> res(g, vector<LL>(g));
	F0R(i, g) res[i][i] = 1;
	return res;
}
 
vector<vector<LL>> mult(vector<vector<LL>> a, vector<vector<LL>> b){
	vector<vector<LL>> res(n, vector<LL>(n));
	F0R(i, n)
		F0R(j, n)
			F0R(z, n)
				res[i][j] = (res[i][j] + (a[i][z] * b[z][j]) % MOD) % MOD;
	return res;
}
 
vector<vector<LL>> expo(vector<vector<LL>>& a, LL p){
	vector<vector<LL>> res = identity(n);
	vector<vector<LL>> mul = a;
	for(; p; p >>= 1, mul = mult(mul, mul)){
		if(p & 1) 
			res = mult(mul, res);
	}
 
	return res;
}
 
vector<LL> multi(vector<vector<LL>> a, vector<LL> b){
	vector<LL> res(n);
	F0R(i, n)
		F0R(j, n)
			res[i] = (res[i] + (a[i][j] * b[j]) % MOD) % MOD;
		
	return res;
}
 
void solve(){
	cin >> n >> m >> k;
	vector<vector<LL>> a(n, vector<LL>(n));
 
	while(m--){
		LL t1, t2;
		cin >> t1 >> t2;
		t1--;t2--;
		a[t2][t1]++;
	}
 
	a = expo(a, k);
 
	vector<LL> c(n, 0);
	c[0] = 1;
 
	c = multi(a, c);
 
	cout << c[n - 1] << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
 
	T = 1;
	//cin >> T;
	FOR(t, T)
		solve();
 
	cout.flush();
	return 0;
}
 