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
    ListNode* reverseList(ListNode* head) {
        if(!head||head->next==nullptr) return head;
        ListNode *rehead=nullptr;
        ListNode *cur=head;
        while(cur)
        {
            ListNode *tempCur=cur->next;
            cur->next=rehead;
            rehead=cur;
            cur=tempCur;
        }
        return rehead;
    }

};
