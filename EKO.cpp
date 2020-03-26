PROBLEM:

Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.
Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.
Input
The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).
The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.
Output
The first and only line of output must contain the required height setting.
Example
Input:
4 7
20 15 10 17

Output:
15
Input:
5 20
4 42 40 26 46

Output:
36

SOLUTION:

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define abs(x) (x<0?(-x):x)
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

bool ispossible(int a[],int n,int m,int mid)
{
    long long s=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>mid)
            s+=a[i]-mid;
    }

    if(s>=m)
        return true;
    else
        return false;
}

int main() {
    fastio;

    int n,m,i;
    cin>>n>>m;

    int a[n];

    for(i=0;i<n;i++)
    cin>>a[i];

    sort(a,a+n);

    int l=0;
    int h=a[n-1];
    int ans=-1;

    while(l<=h)
    {
        int mid=l+(h-l)/2;

        if(ispossible(a,n,m,mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }

    cout<<ans<<endl;

    return 0;
}
