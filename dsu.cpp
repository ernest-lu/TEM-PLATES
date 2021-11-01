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
LL T;

struct DSU{
	LL mxn;
	vector<LL> par, sz;

	DSU(LL ini){
		mxn = ini;
		par.assign(ini + 5, 0);
		sz.assign(ini + 5, 1);
		FOR(i, mxn) par[i] = i;
	}

	LL fnd(LL g){
		if(g == par[g]) return g;
 		return par[g] = fnd(par[g]);
	}

	void uni(LL a, LL b){
		a = fnd(a), b = fnd(b);
		if(a == b) return;

		if(sz[a] <= sz[b]) swap(a, b); // a bigger
		par[b] = a; sz[a] += sz[b];
	}
};

void solve(){
	DSU test(6);

	test.uni(3, 4);
	FOR(i, 6)
		cout << test.fnd(i) << '\n';
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

