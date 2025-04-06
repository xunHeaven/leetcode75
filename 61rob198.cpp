class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        vector<int> index(n,0);
        res.push_back(nums[0]);

        if(n>=2)
        {
            if(nums[0]<nums[1])
            {
                res.push_back(nums[1]);
            }
            else{
                res.push_back(nums[0]);
            }
            //res.push_back(nums[1]);
            for(int i=2;i<n;i++)
            {
                if(res[i-2]+nums[i]>res[i-1])
                {
                    res.push_back(res[i-2]+nums[i]);
                }
                else
                {
                    res.push_back(res[i-1]);
                }
            }
        }
        return res[n-1];
    }
};
