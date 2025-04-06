class Solution {
public:
    int tribonacci(int n) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        res.push_back(1);
        /*if(n==0)
        {
            return 0;
        }
        if(n==1||n==2)
        {
            return 1;
        }
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);*/
        for(int i=3;i<=n;i++)
        {
            res.push_back(res[i-1]+res[i-2]+res[i-3]);
        }
        return res[n];
    }
};
