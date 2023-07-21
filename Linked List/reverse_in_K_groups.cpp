class Solution
{
    public:
    node* reversek(node* head,int k){
        if(!head || !head->next){
            return head;
        }
        // reversing k nodes
        node* prev=NULL;
        node* cur=head;
        node* nxt;
        int i=0;
        while(i<k && cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            i++;
        }
        // reversing the next group and adding it after currents group's head
        if(nxt){
            head->next=reversek(nxt,k); // head for next group is nxt
        }
        return prev; // prev will be new head after reversing
    }

    node *reverse (node *head, int k)
    { 
        return reversek(head,k);
    }
};