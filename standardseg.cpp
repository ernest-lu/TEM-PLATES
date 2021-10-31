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
const LL INF = 1e18;

struct seg{
	vector<LL> tr;
	LL mxn;

	seg(LL sz){
		mxn = sz;
		tr.assign(2 * sz + 5, INF);
	}

	void upd(LL g, LL k){
		g--;
		for(tr[g += mxn] = k; g > 1; g >>= 1)
			tr[g / 2] = min(tr[g], tr[g ^ 1]);
	}

	LL ge(LL l, LL r){
		l--; LL res = INF;
		for(l += mxn, r += mxn; l < r; l >>= 1, r >>= 1){
			if(l & 1) res = min(res, tr[l++]);
			if(r & 1) res = min(res, tr[--r]);
		} return res;
	}
};

void solve(){
	LL n, q;
	cin >> n >> q;
	vector<LL> a(n + 5);
	seg tr(n);
	FOR(i, n){
		cin >> a[i];
		tr.upd(i, a[i]);
	}

	while(q--){
		LL t1, t2;
		cin >> t1 >> t2;
		cout << tr.ge(t1, t2) << '\n';
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

