class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size();
        vector<vector<int> > res(len,vector<int> (2,0));
        res[0][0]=0,res[0][1]=-prices[0];
        for(int i=1;i<len;i++)
        {
            res[i][0]=max(res[i-1][0],res[i-1][1]+prices[i]-fee);
            res[i][1]=max(res[i-1][0]-prices[i],res[i-1][1]);
        }
        return res[len-1][0];
    }
};
