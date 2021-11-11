#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//gp_hash_table<int, int> table;
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
const LL MOD = 998244353;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
}; //only for integers?


//var 

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

