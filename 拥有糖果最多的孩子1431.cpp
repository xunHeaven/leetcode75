class Solution {
public:
//思路：用糖果最多的孩子的糖果减去额外的糖果得到关键值keyV，只有拥有糖果数大于keyV的孩子才能返回true
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy=0;
        int len=candies.size();
        vector<bool> result;
        for(int i=0;i<len;i++)
        {
            if(candies[i]>maxCandy)
            {
                maxCandy=candies[i];
            }
        }
        int keyV=maxCandy-extraCandies;
        for(int i=0;i<len;i++)
        {
            if(candies[i]>=keyV)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
        
    }
};
