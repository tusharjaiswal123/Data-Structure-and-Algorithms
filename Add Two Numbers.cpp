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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *head,*curr,*n,*p;
        head=NULL;
        int s,c=0,a,b;
        
        while(l1!=NULL || l2!=NULL)
        {   
            a=b=0;
            
            if(l1!=NULL)
            {
                a = l1->val;
                l1=l1->next;
            }
            
            if(l2!=NULL)
            {
                b = l2->val;
                l2=l2->next;
            }
            
            s = c+a+b;
            if(head==NULL)
            {
                head = new ListNode(s%10);
                p = head;
            }
            else
            {
                p->next = new ListNode(s%10);
                p = p->next;
            }
            c = s/10;
        }
        
        while(c)
        {
            if(head==NULL)
            {
                head = new ListNode(c%10);
                p = head;
            }
            else
            {
                p->next = new ListNode(c%10);
                p = p->next;
            }
            c=c/10;
        }
        
      
        return head;
    }
};
