class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> res;
        res.push_back(0);
        res.push_back(0);
        for(int i=2;i<=n;i++)
        {
            int min_add=min(res[i-2]+cost[i-2],res[i-1]+cost[i-1]);
            res.push_back(min_add);
        }
        return res[n];
    }
};
