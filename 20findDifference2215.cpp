//解题思路参考https://leetcode.cn/problems/find-the-difference-of-two-arrays/solutions/2841863/javapython3cha-xi-biao-mo-ni-zhuan-wei-h-r7m8
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());
        auto search=[&](unordered_set<int> s1,unordered_set<int> s2,int idx)
        {
            for(auto num:s1)
            {
                if(s2.find(num)==s2.end())//如果s2中没有与num匹配的值，则指向空
                {
                    answer[idx].emplace_back(num);
                }
            }
        };
        //枚举集合1的元素，找出不在集合2中的元素
        search(set1,set2,0);
        //枚举集合2的元素，找出不在集合1中的元素
        search(set2,set1,1);
        return answer;
    }
};
