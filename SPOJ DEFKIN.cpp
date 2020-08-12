PROBLEM:

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells.
The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.
The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

Help Theodore write a program that calculates the penalty of the given position.
Input
The first line of the input file contains the number of test cases.
Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers
(1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).
Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
Output
For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.


SOLUTION;

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define f(i,k) for(i=1;i<=k;i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define ALL(c) (c).begin(),(c).end()
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}



int main() {
    fastio;

    int t;
    cin>>t;

    while(t--)
	{
		int w,h,n,i,ans,max_x,max_y,u,v;
		cin>>w>>h>>n;

		int a[n+1],b[n+1];

		for(i=0;i<n;i++)
		{
			cin>>a[i]>>b[i];
		}

        a[n]=w+1;
        b[n]=h+1;

		sort(a,a+n+1);
		sort(b,b+n);

        max_x=a[0];
        max_y=b[0];

		for(i=1;i<n+1;i++)
		{
		    u=a[i]-a[i-1];
		    v=b[i]-b[i-1];

		    max_x=max(max_x,u);
		    max_y=max(max_y,v);
		}

		ans=(max_x-1)*(max_y-1);

		if(n==0)
            ans=w*h;

        cout<<ans<<endl;


	}

    return 0;
}
