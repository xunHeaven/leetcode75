class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len=nums.size();
        vector<int> leftSum;
        vector<int> rightSum;
        int left=0;
        int right=0;
        leftSum.emplace_back(0);
        rightSum.emplace_back(0);

        for(int i=1;i<len;i++)
        {
            left+=nums[i-1];
            right+=nums[len-i];
            leftSum.emplace_back(left);
            rightSum.emplace(rightSum.begin(),right);
            
        }
        //int index=-1;
        for(int i=0;i<len;i++)
        {
            if(leftSum[i]==rightSum[i])
            {
                //index=1;
               return i;
            }
        }
        return -1;

    }
};
