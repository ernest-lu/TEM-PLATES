#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,pii> ppi;
typedef pair<pii,pii> ppp;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {cout << "["; F0R(i, v.size()) {if (i) cout << ", "; cout << v[i];} return cout << "]";}

//var
const LL MOD = 1e9 + 7; 
LL T;

LL pwo(LL a1, LL b1){
	LL res = 1;
	for(LL mul = a1; b1; b1 >>= 1, mul = (mul * mul) % MOD)
		if(b1 & 1)
			res = (res * mul) % MOD;
	return res;
}

void solve(){
	LL a, b;
	cin >> a >> b;
	cout << pwo(a, b) << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	T = 1;
	cin >> T;
	FOR(t, T)
		solve();

	cout.flush();
	return 0;
}

