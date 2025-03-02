//滑动窗口，解类似16题
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len=nums.size();
        int left=0;
        int right=0;
        int count0=0;
        int maxWind=0;
        for(right;right<len;right++)
        {
            if(nums[right]==0)
            {
                count0++;
            }
            while(count0>1)
            {
                if(nums[left]==0)
                {
                    count0--;
                }
                left++;
            }
            maxWind=max(maxWind,right-left+1);
        }
        return maxWind-1;

    }
};
