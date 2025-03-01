class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len=nums.size();
        double max_avg=0;
        double temp_avg=0;
        double sum=0;
        if(len>=k)
        {
            for(int i=0;i<k;i++)
            {
                sum+=nums[i];
            }
            temp_avg=sum/k;
            max_avg=temp_avg;
        }
        for(int i=1;i<=len-k;i++)
        {
            sum=sum-nums[i-1]+nums[i+k-1];
            temp_avg=sum/k;
            if(max_avg<temp_avg)
            {
                max_avg=temp_avg;
            }
        }
        return max_avg;
    }
};
