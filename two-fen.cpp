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

struct twoFen{
	//fast logn range update incremenet, range query sum
	vector<LL> tr1, tr2;
	LL mxn;

	twoFen(LL sz){
		mxn = sz;
		tr1.assign(sz + 5, 0);
		tr2.assign(sz + 5, 0);
	}

	void upd1(LL g, LL k){
		for(; g <= mxn; g += g&-g)
			tr1[g] += k;
	}

	void upd2(LL g, LL k){
		for(; g <= mxn; g += g&-g)
			tr2[g] += k;
	}

	LL ge1(LL g){
		LL res = 0;
		for(; g; g -= g&-g)
			res += tr1[g];
		return res;
	}

	LL ge2(LL g){
		LL res = 0;
		for(; g; g -= g&-g)
			res += tr2[g];
		return res;
	}

	LL upd(LL l, LL r, LL k){
		upd1(l, k);
		upd1(r + 1, -k);

		upd2(l, -(l - 1) * k);
		upd2(r + 1, (r) * k);
	}

	LL pfix(LL g){return g * ge1(g) + ge2(g);}
	LL rng(LL l, LL r){return pfix(r) - pfix(l - 1);}
};

void solve(){
	twoFen tr(10);

	tr.upd(1, 3, 5);

	cout << tr.rng(1, 10) << '\n';

	tr.upd(2, 10, 4);
	//cout << tr.rng(1, 10) << '\n';
	//cout << tr.rng(2, 9) << '\n';
	
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

