1
/*
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")
#include "bits/stdc++.h"
using namespace std;

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define TS(x) #x
#define x first
#define y second
#define pack(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define gi(x,v) lower_bound(all(x),v)-x.begin()
#define int long long

using ll = long long;
using pii = pair<int, int>;
const int INF = 2e15;
const int MOD = 1e9+7;
using ld = long double;
using vi = vector<int>;
using ull = unsigned long long;

using B = bitset<4000>;
using P = pair<B, int>;
struct cmp{
	bool operator()(const P &x, const P &y) const{
		for (int i = 3999; i >= 0; --i) {
			if (x.x[i] ^ y.x[i]) return y.x[i];
		}
		return x.y < y.y;
	}
};

void solve()
{
	int n, b, r;
	cin>>n>>b>>r;
	vi a(n);
	rep(i,0,n)cin>>a[i];
	int mod = 0;
	int cnt = 0;
	int left = 0;

	set<P, cmp> s;
	vector<B> v;
	vi cntVec(1);
	B bit;
	vi hasleft(1);
	while (1)
	{
		bit = B();
		rep(i,0,n)
		{
			left += a[i];
			if (left + a[(i + 1) % n] > b)
			{
				++cnt;
				bit[i] = 1;
				left = 0;
			}
		}
		if (s.count(P(bit, left)))
			break;
		cntVec.push_back(cnt);
		hasleft.push_back(!!left);
		s.insert(P(bit, left));
		v.push_back(bit);
		++mod;
	}
	int st;
	for (st = 0; v[st] != bit; ++st)
		;
	int ed = (int)v.size();
	if (r < ed){
		cout<<cntVec[r] + hasleft[r]<<'\n';
	}
	else{
		int ans = cntVec[st];
		r -= st;
		ans += (r / (ed - st)) * (cntVec[ed] - cntVec[st]);
		if (r % (ed - st) == 0){
			ans += hasleft[ed];
		}
		else{
			ans += cntVec[st + r % (ed - st)] - cntVec[st] + hasleft[st + r % (ed - st)];
		}
		cout<<ans<<'\n';
	}
}

signed main()
{
	int t;cin>>t;
	while(t--)
		solve();
	return (0);
}
*/
