class Solution {
public:
class Comp{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode * head=new ListNode();
        ListNode* tmp_head=head;
        priority_queue<ListNode*,vector<ListNode*>,Comp> pq;

        for(int i=0;i<lists.size();i++){
             ListNode* node=lists[i];
            if(node){
                pq.push(node);
            }
        }
        
        while(!pq.empty()){
            tmp_head->next=pq.top();
            tmp_head=tmp_head->next;
            if(tmp_head->next){
                 pq.push(tmp_head->next);
            }           
            pq.pop();
        }

        return head->next;
    }
};
