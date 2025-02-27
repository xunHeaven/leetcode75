class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
//解题思路参考：https://leetcode.cn/problems/increasing-triplet-subsequence/solutions/66089/c-xian-xing-shi-jian-fu-za-du-xiang-xi-jie-xi-da-b
        int small=INT_MAX;
        int mid=INT_MAX;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            if(nums[i]<=small)
            {
                small=nums[i];
            }
            else if(nums[i]<=mid)
            {
                mid=nums[i];
            }
            else if(mid<nums[i])
            {
                return true;
            }
        }
        return false;
    }
};
