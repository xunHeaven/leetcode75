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
    ListNode* oddEvenList(ListNode* head) {
        if((!head||(head->next==nullptr))) return head;
        ListNode* oddList=head, *evenList=head->next;
        ListNode* evenHead=evenList;
        ListNode* oddHead=oddList;
        ListNode* temp=head;
        int count1=1;
        while(temp)
        {
            if(count1>2)
            {
                if(count1%2==0)
                {
                    evenList->next=temp;
                    evenList=evenList->next;
                }
                else
                {
                    oddList->next=temp;
                    oddList=oddList->next;
                }
            }
            temp=temp->next;
            count1++;
            
        }
        evenList->next=nullptr;
        oddList->next=evenHead;
        return oddHead;
        //return head;
    }
};
