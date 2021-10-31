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

struct fen{
	vector<LL> tr;
	LL mxn;

	fen(LL sz){
		mxn = sz;
		tr.assign(sz + 5, 0);
	}

	void upd(LL g, LL k){
		for(; g <= mxn; g += g&-g)
			tr[g] += k;
	}

	LL ge(LL g){
		LL res = 0;
		for(; g; g -= g&-g)
			res += tr[g];
		return res;
	}
};

void solve(){
	LL n, q;
	cin >> n >> q;
	fen tr(n);
	vector<LL> a(n + 5);

	FOR(i, n){
		LL t1;
		cin >> t1;
		a[i] = t1;
		tr.upd(i, t1);
	}

	while(q--){
		LL t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if(t1 == 1) {
			tr.upd(t2, -a[t2]);
			tr.upd(t2, t3);
			a[t2] = t3;
		} else{
			cout << tr.ge(t3) - tr.ge(t2 - 1) << '\n';
		}
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

