PROBLEM:

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their
nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


SOLUTION:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v;
        v.clear();
        
        ListNode *t1,*t2,*p,*head=NULL,*prev;
        
        t1=l1;
        t2=l2;
        int c=0,s;
        
        while(t1!=NULL && t2!=NULL)
        {
            s=(t1->val+t2->val+c)%10;
            c=(t1->val+t2->val+c)/10;
            ListNode *newnode=new ListNode(s);
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
                prev->next=newnode;
            }
            prev=newnode;
            t1=t1->next;
            t2=t2->next;
            
        }
        
        while(t1)
        {
            s=(t1->val+c)%10;
            c=(t1->val+c)/10;
            ListNode *newnode=new ListNode(s);
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
                prev->next=newnode;
            }
            prev=newnode;
            
            t1=t1->next;
        }
        
        while(t2)
        {
            s=(t2->val+c)%10;
            c=(t2->val+c)/10;
            ListNode *newnode=new ListNode(s);
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
                prev->next=newnode;
            }
            prev=newnode;
            
            t2=t2->next;
        }
        
        if(c!=0)
        {
            ListNode *newnode=new ListNode(c);
            prev->next=newnode;
        }
        
        return head;
    }
};
