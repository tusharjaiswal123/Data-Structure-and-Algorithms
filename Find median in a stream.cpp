#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,a,m;
	cin>>n;
	
	priority_queue<int,vector<int>,greater<int>> qmin;
	priority_queue<int> qmax;
	
	
	for(i=0;i<n;i++)
	{   
	    cin>>a;
		
	    if(qmax.empty() || a<qmax.top())
	    qmax.push(a);
	    else
	    qmin.push(a);
	    
	    if(qmax.size()>qmin.size()+1)
	    {
	     	qmin.push(qmax.top());
		    qmax.pop();
	    }
		
	    if(qmin.size()>qmax.size()+1)
	    {
	     	qmax.push(qmin.top());
		    qmin.pop();
	    }
		
	    if(qmin.size()==qmax.size())
            m=(qmin.top()+qmax.top())/2.0;
        
       	    if(qmax.size()>qmin.size())
            m=qmax.top();
        	
	    if(qmin.size()>qmax.size())
       	    m=qmin.top();
		
	    cout<<m<<endl;
	    
	}
	
	
	return 0;
	
}






Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
	
	
	
	
	

SOLUTION:




class MedianFinder {
    private:
    
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left.empty() || num<left.top())
            left.push(num);
        else
            right.push(num);
        
        if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }
        
        if(right.size()>left.size()+1)
        {
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        
        if(left.size()==right.size())
            return (left.top()+right.top())/2.0;
        
        if(left.size()>right.size())
            return left.top();
        
        return right.top();
        
    }
};
