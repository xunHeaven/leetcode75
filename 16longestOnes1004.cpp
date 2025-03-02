//滑动窗口
//题解参考https://leetcode.cn/problems/max-consecutive-ones-iii/solutions/609055/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len=nums.size();
        int left=0;
        int right=0;
        int lenWind=0;
        int count0=0;
        int maxWind=0;
        for(right;right<len;right++)
        {
            if(nums[right]==0)
            {
                count0++;
            }
            while(count0>k)
            {
                if(nums[left]==0) count0--;
                left++;
            }
            maxWind=max(maxWind,right-left+1);
        }
        return maxWind;
    }
};
