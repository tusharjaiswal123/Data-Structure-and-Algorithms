Node * mergeKLists(Node *arr[], int N)
{
    priority_queue<Node *,vector<Node *>,greater<Node*>> q;
    
    int i;
    
    for(i=0;i<N;i++)
    {
        if(arr[i]!=NULL)
        q.push(arr[i]);
    }
    
    Node *head=NULL;
    Node *curr;
    
    while(!q.empty())
    {
        Node *temp=q.top();
        q.pop();
        
        if(temp->next!=NULL)
        q.push(temp->next);
        
        if(head==NULL)
        {
            head=temp;
            curr=temp;
        }
        else
        {
        curr->next=temp;
        curr=temp;
        }
    
    }
    
    return head;
}





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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int i,n;
        n = lists.size();
        ListNode *head=NULL,*p;
        
        if(n==0)
            return head;
        
        priority_queue< pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>> > pq;
        
        for(i=0;i<n;i++)
        {   
            if(lists[i]!=NULL)
            {
                pq.push({lists[i]->val,lists[i]});
            }
        }
        
        
        while(!pq.empty())
        {
            auto k=pq.top();
            pq.pop();

            
            if(head==NULL)
            {
                head=k.second;
                p=head;
            }
            else
            {
                p->next=k.second;
                p=p->next;
            }
            
            if((k.second)->next!=NULL)
            {
                pq.push({(k.second->next)->val,k.second->next});
            }
            
        }
        
        
        return head;
    }
};





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
    struct cmp{
        bool operator()(const ListNode *a,const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int i,n;
        n = lists.size();
        ListNode *head=NULL,*p;
        
        if(n==0)
            return head;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp > pq;
        
        for(i=0;i<n;i++)
        {   
            if(lists[i]!=NULL)
            {
                pq.push(lists[i]);
            }
        }
        
        
        while(!pq.empty())
        {
            auto k=pq.top();
            pq.pop();

            
            if(head==NULL)
            {
                head=k;
                p=head;
            }
            else
            {
                p->next=k;
                p=p->next;
            }
            
            if(k->next!=NULL)
            {
                pq.push(k->next);
            }
            
        }
        
        
        return head;
    }
};
