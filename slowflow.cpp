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

struct FF{
	LL n, sumEdges = 0, minEdge;
	vector<map<LL, LL>> e;
	vector<LL> curPath;

	FF (LL nodes, vector<array<LL, 3>> edges) {
		n = nodes;
		e.resize(n + 5);
		for (auto& [u, v, c] : edges) {
			e[u][v] += c;
			e[v][u] += 0;
			sumEdges += c;
		}
	}

	bool findPath(LL source, LL sink) {
		vector<LL> par(n + 5), v(n + 5);
		queue<pii> bfs;
		bfs.push({source, 0});
		while (!bfs.empty()) {
			auto [g, p] = bfs.front();
			bfs.pop();

			if (v[g]) continue;
			v[g] = 1;
			par[g] = p;

			for (auto [u, nxtWeight] : e[g]) {
				if (v[u] || nxtWeight == 0) continue;
				bfs.push({u, g});
			}	
		}
		if (!v[sink]) return false;
		curPath.clear(); minEdge = sumEdges;
		LL x = sink;
		while (x != 0) {
			curPath.pb(x);
			if (par[x] != 0) minEdge = min(minEdge, e[par[x]][x]);
			x = par[x];
		}
		reverse(all(curPath));
		return true;
	}

	LL maxFlow(LL source, LL sink) {
		LL ans = 0;
		while (findPath(source, sink)) {
			LL prv = 0;
			for (auto u : curPath) {
				if (prv != 0) {
					e[prv][u] -= minEdge;
					e[u][prv] += minEdge;
				}
				prv = u;
			}
			ans += minEdge;
		}
		return ans;
	}
};

void solve(){
	LL n, m;
	cin >> n >> m;

	vector<array<LL, 3>> edges(m);
	for (auto& [t1, t2, t3] : edges) {
		cin >> t1 >> t2 >> t3;
	}

	FF flower(n, edges);
	cout << flower.maxFlow(1, n) << '\n';
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

