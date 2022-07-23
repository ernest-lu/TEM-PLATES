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

const LL MOD = 998244353, PRIMITIVE = 3;
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
namespace NTT {
 
  // for mod 998244353
 
  vector<mint> aux;
 
  vector<mint> dft(vector<mint> a, bool rev) {
    int N = a.size();
    aux.resize(N);
    for (int n = N; n > 1; n /= 2) {
      int c = 0;
      for (int i = 0; i < N; i += n) {
        for (int j = 0; j < n; j += 2)
          aux[c++] = a[i + j];
        for (int j = 1; j < n; j += 2)
          aux[c++] = a[i + j];
      }
      swap(aux, a);
    }
 
    for (int n = 2; n <= N; n *= 2) {
      mint mul = mint(PRIMITIVE).pow((MOD - 1) / n);
      if (rev) mul = mul.pow();
 
      for (int i = 0; i < N; i += n) {
        mint cp = 1;
        for (int j = 0; j < n; j++) {
          int ps = n / 2;
          mint cv = a[i + (j % ps)]; // even
          cv += (cp * a[i + ps + (j % ps)]); // odd
          aux[i + j] = cv;
          cp *= mul;
        }
      }
      swap(a, aux);
    }
 
    if (rev) {
      mint ninv = mint(N).pow();
      for (mint &i : a)
        i *= ninv;
    }

    return a;
  }
 
  vector<mint> convolution(vector<mint> a, vector<mint> b) {
 
    int cs = max(a.size(), b.size()) * 2;
    int n = 1; while (n < cs) n *= 2;
 
    while (a.size() < n) a.push_back(0);
    while (b.size() < n) b.push_back(0);
 
    a = dft(a, 0); b = dft(b, 0);
 
    vector<mint> res;
    for (int i = 0; i < a.size(); i++)
      res.push_back((a[i] * b[i]));
 
    res = dft(res, 1);
    while (res.back() == 0) res.pop_back();
    return res;
 
  }
 
}

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

