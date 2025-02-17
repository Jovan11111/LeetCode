#include <stack>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* prev = nullptr;
        ListNode* next=  nullptr;
        ListNode* cur = head;
        while(cnt != left && cur){
            cnt++;
            cur = cur->next;
        }
        ListNode* cur1 = cur;
        std::stack<int> help;
        while(left != right+1){
            left++;
            help.push(cur1->val);
            cur1 = cur1->next;
        }
        while(cnt != right+1){
            cnt++;
            cur->val = help.top();
            help.pop();
            cur = cur->next;
        }
        return head;
    }
};