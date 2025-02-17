struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ret = new ListNode(0);
        ListNode*cur = ret;
        bool prelaz = false;
        while(l1 || l2){
            if(l1 && l2){
                if(prelaz){
                    prelaz = false;
                    cur->val = (l1->val + l2->val + 1) % 10;
                    if(l1->val + l2->val +1> 9) prelaz = true;
                }
                else{
                    cur->val = (l1->val + l2->val) % 10;
                    if(l1->val + l2->val > 9) prelaz = true;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                if(prelaz){
                    prelaz = false;
                    cur->val = (l1->val+ 1) % 10;
                    if(l1->val +1> 9) prelaz = true;
                    l1 = l1->next;

                }
                else{
                    cur->val = l1->val;
                    l1 = l1->next;

                }
            }
            else if(l2){
                if(prelaz){
                    prelaz = false;
                    cur->val = (l2->val + 1) % 10;
                    if(l2->val+1 > 9) prelaz = true;
                    l2 = l2->next;

                }
                else{
                    cur->val = l2->val;
                    l2 = l2->next;

                }
            }

            if(l1 || l2){cur->next = new ListNode(0);cur = cur->next;}

        }
        if(prelaz){
            cur->next = new ListNode(1);
        }
        return ret;
    }
};