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

const LL MOD = 1e9 + 7;
struct mint {
    int x;
    mint() : x(0) {}
    template <class T> mint(T value) : x(value % MOD) { if (x < 0) x += MOD; }
    mint & operator+=(const mint &oth) { x += oth.x; if (x >= MOD) x -= MOD; return *this; }
    mint & operator-=(const mint &oth) { x -= oth.x; if (x < 0) x += MOD; return *this; }
    mint & operator*=(const mint &oth) { x = (long long) x * oth.x % MOD; return *this; }
    friend mint operator+(mint l, const mint &r) { return l += r; }
    friend mint operator-(mint l, const mint &r) { return l -= r; }
    friend mint operator*(mint l, const mint &r) { return l *= r; }
    mint & operator--() { if (--x == -1) x = MOD - 1; return *this; }
    mint & operator++() { if (++x == MOD) x = 0; return *this; }
    mint operator--(int) { mint temp = *this; --*this; return temp; }
    mint operator++(int) { mint temp = *this; ++*this; return temp; }
    mint operator-() const { return 0 - *this; }
    mint operator+() const { return *this; }
    friend bool operator==(const mint &l, const mint &r) { return l.x == r.x; }
    friend bool operator!=(const mint &l, const mint &r) { return l.x != r.x; }
    friend ostream & operator<<(ostream &out, const mint &a) { return out << a.x; }
    mint pow(long long e = MOD - 2) const {
        mint ans = 1, b = *this;
        while (e > 0) {
            if (e % 2 == 1) {
                ans *= b;
            }
            b *= b;
            e /= 2;
        }
        return ans;
    }
};
//var 
LL T;

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

