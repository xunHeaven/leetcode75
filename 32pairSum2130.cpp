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
    int pairSum(ListNode* head) {
        vector<int> vec;
        while(head)
        {
            vec.push_back(head->val);
            head=head->next;
        }
        int maxSum=0;
        while(vec.size()>0)
        {
            maxSum=max(maxSum,vec[0]+vec[vec.size()-1]);
            vec.erase(vec.begin());
            vec.pop_back();
        }
        return maxSum;

    }
};
