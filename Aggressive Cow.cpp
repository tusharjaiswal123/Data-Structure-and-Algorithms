PROBLEM:

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions
x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the
cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as
large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input: 
1
5 3
1
2
8
4
9
Output: 
3

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

bool ispossible(int a[],int n,int c,int mid)
{
    int pr=a[0];
    int s=1;

    for(int i=1;i<n;i++)
    {
        if(a[i]-pr>=mid)
        {
            s++;
            pr=a[i];
        }

        if(s==c)
            return true;
    }

    if(n==1)
        return true;

    return false;
}

int main() {
    fastio;

    int t;
    cin>>t;

    while(t--)
    {
        int n,c,i;
        cin>>n>>c;

        int a[n];

        for(i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);

        int l=0;
        int h=a[n-1]-a[0];
        int ans=-1;


        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(ispossible(a,n,c,mid))
            {
                   ans=mid;
                   l=mid+1;
            }
            else
                h=mid-1;
        }

        cout<<ans<<endl;
    }

    return 0;
}
