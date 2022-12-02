#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define debug(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define debug(...) "BRUHINT"
#endif

using LL = long long;
using LD = long double;
using pii = pair<LL,LL>;

#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {cout << "["; F0R(i, v.size()) {if (i) cout << ", "; cout << v[i];} return cout << "]";}

const int INF = 1e9;

template<typename T>
struct Min {
	T operator()(T a, T b) {
		return min<T>(a, b);
	}
};

template<typename T, typename Merge = plus<T>>
struct seg {
	int n;
	vector<T> tr;
	Merge merge;
	seg(int n) : n(n), merge(Merge()), tr((n << 2) + 5, T(0)) {};
	
	seg(vector<T> a) : seg((int)a.size()) {
		function<void (int, int, int)> build = [&](int z, int l, int r) {
			if (l == r) {
				tr[z] = a[l - 1];
				return;
			}
			
			int mid = (l + r) >> 1;
			build(2 * z, l, mid);
			build(2 * z + 1, mid + 1, r);
			tr[z] = merge(tr[2 * z], tr[2 * z + 1]);
		};
		build(1, 1, n);
	}
	
	void upd(int z, int l, int r, int qg, T val) {
		if (qg == l && qg == r) {
			tr[z] = val;
			return;
		}
		
		int mid = (l + r) >> 1;
		if (qg <= mid) {
			upd(2 * z, l, mid, qg, val);
		} else {
			upd(2 * z + 1, mid + 1, r, qg, val);
		}
		
		tr[z] = merge(tr[2 * z], tr[2 * z + 1]);
	};
	
	T query(int z, int l, int r, int ql, int qr) {
		if (ql > qr) return T(INF);
		if (ql == l && qr == r) {
			return tr[z];
		}
		
		int mid = (l + r) >> 1;
		return merge(query(2 * z, l, mid, ql, min(qr, mid)),
					 query(2 * z + 1, mid + 1, r, max(ql, mid + 1), qr));
	};
	
	void upd(int g, T val) { upd(1, 1, n, g, val); }
	T query(int l, int r) { return query(1, 1, n, l, r); }
};


//var 
LL T;

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<int> a(n);
	for (auto& u : a) 
		cin >> u;
	
	seg<int, Min<int>> tr(a);

	while (q--) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		
		if (t1 == 1) {
			tr.upd(t2, t3);
		} else {
			cout << tr.query(t2, t3) << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	T = 1;
	//cin >> T;
	FOR(t, T)
		solve();

	cout.flush();
	return 0;
}


