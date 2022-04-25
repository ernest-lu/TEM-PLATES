#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,pii> ppi;
typedef pair<pii,pii> ppp;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {cout << "["; F0R(i, v.size()) {if (i) cout << ", "; cout << v[i];} return cout << "]";}

//var 
LL T;

void solve(){
	LL n;
	cin >> n;
	vector<vector<LL>> e(n + 5);

	FOR (i, n - 1) {
		LL t1, t2;
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}
	vector<LL> sub(n + 5), dep(n + 5), v(n + 5);

	function<void (LL, LL)> dfs_sub = [&](LL g, LL p) {
		sub[g] = 1;
		for (auto u : e[g]) {
			if (u == p || v[u]) continue;
			dfs_sub(u, g);
			sub[g] += sub[u];
		}
	};

	function<LL (LL, LL, LL)> cen = [&](LL g, LL p, LL sz) {
		for (auto u : e[g]) {
			if (u == p || v[u]) continue;
			if (2LL * sub[u] >= sz) return cen(u, g, sz);
		} return g;
	};

	function<void (LL, LL, LL)> dfs_main = [&](LL g, LL p, LL d) {
		for (auto u : e[g]) {
			if (u == p || v[u]) continue;
			dfs_main(u, g, d + 1);
		}
	};

	function<void (LL, LL)> slv = [&](LL g, LL sz) {
		dfs_sub(g, 0);
		g = cen(g, 0, sz);
		dfs_sub(g, 0);
		dfs_main(g, 0, 0);

		v[g] = 1;
		for (auto u : e[g]) {
			if (v[u]) continue;
			slv(u, sub[u]);
		}
	};

	slv(1, n);
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

