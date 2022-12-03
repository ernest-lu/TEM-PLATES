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

template<typename T, typename Merge = plus<T>>
struct lazy_seg{
	int n;
	vector<T> tr, lazy_inc, lazy_ass, tag_inc, tag_ass;
	Merge merge;
	
	void pull(int z) {
		tr[z] = merge(tr[2 * z], tr[2 * z + 1]);
	};
	
	lazy_seg(int n) : n(n), tr(4 * n + 5), lazy_inc(4 * n + 5), lazy_ass(4 * n + 5), tag_inc(4 * n + 5), tag_ass(4 * n + 5), merge(Merge()) {}
	
	lazy_seg(vector<T> a) : lazy_seg((int)a.size()) {
		function<void (int, int, int)> build = [&](int z, int l, int r) {
			if (l == r) {
				tr[z] = a[l - 1];
				return;
			}
			int m = (l + r) >> 1;
			build(2 * z, l, m);
			build(2 * z + 1, m + 1, r);
			pull(z);
		};
		build(1, 1, n);
	}
	
	T f(int l, int r) {
		return r - l + 1;
	}
	
	void push(int z, int l, int r) {
		if (tag_ass[z]) {
			tr[z] = f(l, r) * lazy_ass[z];
             if (l < r) F0R (i, 2) {
             	  lazy_ass[2 * z + i] = lazy_ass[z];
             	  tag_ass[2 * z + i] = true;
             }
		} else if (tag_inc[z]) {
			tr[z] += f(l, r) * lazy_inc[z];
			if (l < r) F0R (i, 2) {
				if (tag_ass[2 * z + i]) {
					lazy_ass[2 * z + i] += lazy_inc[z];
				} else {					
					lazy_inc[2 * z + i] += lazy_inc[z];
					tag_inc[2 * z + i] = true;
				}
			}
		}
		tag_ass[z] = false;
		tag_inc[z] = false;
		lazy_inc[z] = T(0);
		lazy_ass[z] = T(0);
	}
	
	void up_ass(int z, int l, int r, int ql, int qr, T val) {
    	push(z, l, r);
        if (ql > qr) return;		
		if (ql == l && qr == r) {
			lazy_ass[z] = val;
			tag_ass[z] = true;
			push(z, l, r); 
			return;
		} 
		int m = (l + r) >> 1;
		up_ass(2 * z, l, m, ql, min(qr, m), val);
		up_ass(2 * z + 1, m + 1, r, max(ql, m + 1), qr, val);
		pull(z);
	};
	
	void up_inc(int z, int l, int r, int ql, int qr, T val) {
		push(z, l, r);
        if (ql > qr) return;     		
		if (ql == l && qr == r) {
			lazy_inc[z] += val;
			tag_inc[z] = true;
			push(z, l, r); 
			return;
		} 
		int m = (l + r) >> 1;
		up_inc(2 * z, l, m, ql, min(qr, m), val);
		up_inc(2 * z + 1, m + 1, r, max(ql, m + 1), qr, val);
		pull(z);
	};
	
	T query(int z, int l, int r, int ql, int qr) {
		push(z, l, r);
        if (ql > qr) return T(0);
		if (ql == l && qr == r) {
			return tr[z];
		}
		int m = (l + r) >> 1;
		return merge(
			query(2 * z, l, m, ql, min(qr, m)),
			query(2 * z + 1, m + 1, r, max(ql, m + 1), qr)
		);
	};
	
	void up_inc(int l, int r, T val) { return up_inc(1, 1, n, l, r, val); }
	void up_ass(int l, int r, T val) { return up_ass(1, 1, n, l, r, val); }
	T query(int l, int r) { return query(1, 1, n, l, r); }
};


//var 
LL T;

void solve() {
	LL n, q;
	cin >> n >> q;
	
	vector<LL> a(n);
	for (auto& u : a)
		cin >> u;
		
	lazy_seg<LL> tr(a);
	while (q--) {
		LL tt; cin >> tt;
		if (tt == 3) {
			LL l, r; cin >> l >> r;
			cout << tr.query(l, r) << '\n';
		} else {
			LL l, r, x;
			cin >> l >> r >> x;
			if (tt == 2) {
				tr.up_ass(l, r, x);
			} else {
				tr.up_inc(l, r, x);
			}
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


