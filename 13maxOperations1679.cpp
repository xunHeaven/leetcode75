//参考题解https://leetcode.cn/problems/max-number-of-k-sum-pairs/solutions/2807175/pai-xu-shuang-zhi-zhen-by-unruffled-6ang-cr0o
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<=1)return 0;
        sort(nums.begin(),nums.end());
        int left=0,right=len-1;
        int sum=0;
        int times=0;
        while(left<right)
        {
            sum=nums[left]+nums[right];
            if(sum==k)
            {
                left++,right--;
                times++;
            }
            else if(sum<k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return times;
    }
};
