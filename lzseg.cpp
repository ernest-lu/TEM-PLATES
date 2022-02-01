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

struct lzseg{
	vector<LL> tr, lzi, lza, pis;
	LL mxn;
 
	lzseg(LL sz){
		//Might not be 0
		tr.assign(4*sz + 5, 0);
		lzi.assign(4 * sz + 5, 0);
		lza.assign(4*sz + 5, 0);
		pis.assign(4*sz + 5, 0);
		mxn = sz;
	}

	LL join(LL t1, LL t2) {
		return t1 + t2;
	}
 
	void psh(LL z, LL l, LL r){
		LL sz = r - l + 1;
		if(pis[z]){
			tr[z] = sz * lza[z]; //Change depending on operation
			if(l != r){
				pis[2*z] = 1; lza[2*z] = lza[z];
				pis[2*z + 1] = 1; lza[2*z + 1] = lza[z];
			}
		}
		else{
			tr[z] += sz * lzi[z]; //Change depending on operation
			if(l != r){
				if(pis[2*z]) lza[2*z] += lzi[z];
				else lzi[2*z] += lzi[z];
				if(pis[2*z + 1]) lza[2*z + 1] += lzi[z];
				else lzi[2*z + 1] += lzi[z];
			}
		}
		pis[z] = 0; lzi[z] = 0; lza[z] = 0;
	}
 
	void upa(LL z, LL l, LL r, LL lb, LL rb, LL k){
		psh(z, l, r);
		if(r < lb || l > rb) return;
		if(l >= lb && r <= rb){
			pis[z] = 1; lza[z] = k;
			psh(z, l, r);
			return;
		}
 
		LL mid = (l + r) >> 1;
		upa(2*z, l, mid, lb, rb, k);
		upa(2*z + 1, mid+1, r, lb, rb, k);
		tr[z] = join(tr[2*z], tr[2*z + 1]); //remember
	}
 
	void upi(LL z, LL l, LL r, LL lb, LL rb, LL k){
		psh(z, l, r);
		if(r < lb || l > rb) return;
		if(l >= lb && r <= rb){
			lzi[z] += k;
			psh(z, l, r);
			return;
		}
 
		LL mid = (l + r) >> 1;
		upi(2*z, l, mid, lb, rb, k);
		upi(2*z + 1, mid+1, r, lb, rb, k);
		tr[z] = join(tr[2*z], tr[2*z + 1]); //remember
	}
	
	LL ge(LL z, LL l, LL r, LL lb, LL rb){
		psh(z, l, r);
		if(r < lb || l > rb) return 0;
		if(l >= lb && r <= rb) return tr[z];
 
		LL mid = (l + r) >> 1;
		return join(ge(2*z, l, mid, lb, rb),
		ge(2*z + 1, mid+1, r, lb, rb)); //remember
	}
 
	void up_ass(LL l, LL r, LL k){upa(1, 1, mxn, l, r, k);}
	void up_inc(LL l, LL r, LL k){upi(1, 1, mxn, l, r, k);}
	LL rng(LL l, LL r){return ge(1, 1, mxn, l, r);}
};

void solve(){
	
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

