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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p=head;
        if(head->next==nullptr)
        {
            return nullptr;
        }
        int cnt=0;
        while(p)
        {
            cnt++;
            p=p->next;
        }
        int del=cnt/2;
        ListNode* p1=head;
        ListNode* leftP=nullptr;
        for(int i=0;i<del;i++)
        {
            leftP=p1;
            p1=p1->next;
        }
        //leftP->next=leftP->next->next;
        leftP->next=p1->next;
        return head;
    }
};
