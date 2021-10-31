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

//src: https://ekzlib.netlify.app/view/suffix_array.cpp
vector<int> suffix_array(string S) {
	int N = S.size();
	vector<int> sa(N), classes(N);
	for (int i = 0; i < N; i++) {
		sa[i] = N - 1 - i;
		classes[i] = S[i];
	}
	stable_sort(sa.begin(), sa.end(), [&S](int i, int j) {
		return S[i] < S[j];
	});
	for (int len = 1; len < N; len *= 2) {
		vector<int> c(classes);
		for (int i = 0; i < N; i++) {
			bool same = i && sa[i - 1] + len < N
			              && c[sa[i]] == c[sa[i - 1]]
			              && c[sa[i] + len / 2] == c[sa[i - 1] + len / 2];
			classes[sa[i]] = same ? classes[sa[i - 1]] : i;
		}
		vector<int> cnt(N), s(sa);
		for (int i = 0; i < N; i++)
			cnt[i] = i;
		for (int i = 0; i < N; i++) {
			int s1 = s[i] - len;
			if (s1 >= 0)
				sa[cnt[classes[s1]]++] = s1;
		}
	}
	return sa;
}

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

