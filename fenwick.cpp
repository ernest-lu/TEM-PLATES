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

	LL rng(LL l, LL r){return ge(r) - ge(l - 1);}

	//maxi and mini only work with positive numbers
	LL maxi(LL k){
		//max i such that ge(i) <= k.
		//log(n) vs log^2(n) binary search
		LL running = 0, res = 0;
		LL lg = 32 - __builtin_clz(mxn);

		for(int i = lg; i>=0; i--){
			if(res + (1LL << i) > mxn) continue;
			if(running + tr[res + (1LL << i)] > k) continue;
			running += tr[res + (1LL << i)];
			res += (1LL << i);
		}

		return res;
	}

	LL mini(LL k){
		//kth order statistic
		LL running = 0, res = 0;
		LL lg = 32 - __builtin_clz(mxn);

		for(int i = lg; i>=0; i--){
			if(res + (1LL << i) > mxn) continue;
			if(running + tr[res + (1LL << i)] >= k) continue;
			running += tr[res + (1LL << i)];
			res += (1LL << i);
		}

		return res + 1;
	}
};

void solve(){
	LL n, q;
	cin >> n >> q;
	fen tr(1000000);

	//te
	FOR(i, n){
		LL x; cin >> x;
		tr.upd(x, 1);
		//cout << x << "\n";
	}

	while(q--){
		LL t1;
		cin >> t1;
		if(t1 > 0){
			tr.upd(t1, 1);
			continue;
		}

		t1 = -t1;
		tr.upd(tr.mini(t1), -1);
	}

	LL ans = tr.mini(1);
	if(ans > 1000000){
		cout << 0 << "\n";
		return;
	} cout << ans << "\n";
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

