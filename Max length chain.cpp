PROBLEM:

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow .Then T test cases follow . The first line of input contains an integer N denoting the no of pairs . In the next line are 2*N space separated values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 

Output
3
1


SOLUTION:


bool cmp(struct val a,struct val b)
{
    return (a.first < b.first);
}    
    
/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{   
    sort(p,p+n,cmp);         //sort in ascending order according to first and apply LIS
    
    int dp[n];
    
    int i,j,ans=INT_MIN;
    
    for(i=0;i<n;i++)
    {   
        dp[i]=1;
        for(j=0;j<i;j++)
        {
            if(p[i].first>p[j].second)
            dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    
    return ans;
}
