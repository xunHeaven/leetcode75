class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast=0,slow=0,n=nums.size();
        //如果有0慢指针指向0，快指针寻找0之后的第一个非0；
        int temp;
        for(int i=0;i<n;i++)
        {
            if(nums[slow]==0)//当慢指针指向0时
            {
                if(nums[fast]!=0)//如果快指针指向非0，则交换数据，并且两个指针右移
                {
                    nums[slow]=nums[fast];
                    nums[fast]=0;
                    fast++,slow++;
                }
                else{//如果快指针指向0时，则只有快指针右移
                    fast++;
                }
            }
            else{//当慢指针指向非0时，两个指针同时右移
                fast++,slow++;
            }
            
        }
        //return nums;

    }
};
