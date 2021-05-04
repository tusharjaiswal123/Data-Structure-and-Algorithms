#include <bits/stdc++.h>
using namespace std;
const int N=10005;

int par[N];
int r[N];

int find(int i)
{
    if(par[i]==-1)
    {
        return i;
    }

    return par[i]=find(par[i]);
}

void merge(int s1,int s2)
{
    int p1=find(s1);
    int p2=find(s2);

    if(p1!=p2)
    {
        if(r[p1]>r[p2])
        {
            par[p2]=p1;
            r[p1]+=r[p2];
        }
        else
        {
            par[p1]=p2;
            r[p2]+=r[p1];
        }
    }
}

int main() {
    
    int n,e,i,u,v,w,ans=0;
    cin>>n>>e;

    vector< pair< int, pair <int,int> > > a;

    for(i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        a.push_back({{w},{u,v}});
    }

    sort(a.begin(),a.end());
    
    for(i=0;i<n;i++)
    {
        par[i]=-1;
        r[i]=1;
    }

    for(i=0;i<e;i++)
    {
        w=a[i].first;
        u=a[i].second.first;
        v=a[i].second.second;

        if(find(u)!=find(v))
        {
            merge(u,v);
            ans+=w;
        }
    }

    cout<<ans<<endl;


    return 0;
}


Alt:

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" = "<<x<<"  "<<#y<<" = "<<y<<endl;
#define print(x) for (auto k:x) cout<<k<<" ";cout<<endl;
#define debmp(x) for(auto k:x) cout<<k.first<<" "<<k.second<<endl;
#define ll long long
#define mod 998244353
#define ff first
#define ss second
#define pb push_back
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

ll add(ll a, ll b) {a = a % mod; b = b % mod; return ((a + b) % mod + mod) % mod;}
ll sub(ll a, ll b) {a = a % mod; b = b % mod; return ((a - b) % mod + mod) % mod;}
ll mul(ll a, ll b) {a = a % mod; b = b % mod; return ((1ll * a * b) % mod + mod) % mod;}
ll expo(ll a, ll n) {ll ans = 1; a = a % mod; while (n) {if (n % 2) {ans = ((ans % mod) * (a % mod)) % mod; n--;} else {a = ((a % mod) * (a % mod)) % mod; n = n / 2;}} return ans;}
ll dv(ll a, ll b) {a = a % mod; b = b % mod; return (a * expo(b, mod - 2)) % mod;}

void solve();


int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;

	//cin >> t;
	for (ll test = 1; test <= t; test++)
	{
		//cout << "Case #" << test << ": ";
		solve();
	}
	return 0;
}


struct dsu
{
	vll par;
	vll r;;

	void init(ll n)
	{
		r.assign(n + 10, 1);
		par.resize(n + 10);

		for (ll i = 1; i <= n + 5; i++)
		{
			par[i] = i;
		}
	}

	ll get(ll x)
	{
		return par[x] = (par[x] == x ? x : get(par[x]));
	}

	bool merge(ll a, ll b)
	{
		ll p1 = get(a);
		ll p2 = get(b);

		if (p1 != p2)
		{
			if (r[p1] > r[p2])
				swap(p1, p2);

			par[p1] = p2;

			r[p2] += r[p1];

			return true;
		}

		return false;
	}

};


inline void solve()
{
	ll n, m, i, x, u, v, ans = 0;
	cin >> n >> m;

	dsu s;
	s.init(n);

	vector<tuple<ll, ll, ll>> edge;

	for (i = 0; i < m; i++)
	{
		cin >> u >> v >> x;
		edge.pb({x, u, v});
	}

	sort(edge.begin(), edge.end());

	for (auto k : edge)
	{
		tie(x, u, v) = k;

		if (s.merge(u, v))
		{
			ans += x;
		}
	}

	cout << ans << endl;
}
