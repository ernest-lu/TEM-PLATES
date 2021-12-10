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

const int INF = 2e9;

struct sparse{
	vector<vector<int>> tr, bl;
	int mxn, loggy;

	int l0g(int g) {
		return 32 - __builtin_clz(g);
	}

	sparse(vector<int>& g){
		mxn = (int)g.size();
		loggy = l0g(mxn);
		tr.assign(mxn + 5, vector<int>(loggy + 1, 0));
		bl.assign(mxn + 5, vector<int>(loggy + 1, 0));

		for (int i = 1; i <= mxn; i++) {
			tr[i][0] = g[i - 1];
			bl[i][0] = i + 1;
		}

		for (int j = 1; j <= loggy; j++) {
			for (int i = 1; i <= mxn; i++) {
				bl[i][j] = bl[bl[i][j - 1]][j - 1];
				tr[i][j] = max(tr[i][j - 1], tr[bl[i][j - 1]][j - 1]);
			}
		}
	}

	int rmq(int l, int r) {
		int j = l0g(r - l + 1); j--;
		int rb = r - (1 << j) + 1;
		return max(tr[l][j], tr[rb][j]);
	}
};

//var 
LL T;

void solve(){
	LL n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (auto& u : a) cin >> u;

	sparse tr(a);

	//cout << a << "\n";

	while (q--) {
		LL l, r; cin >> l >> r;
		cout << tr.rmq(l, r) << '\n';
	}
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

