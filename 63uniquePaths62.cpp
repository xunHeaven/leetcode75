class Solution {
    
public:
   
    int uniquePaths(int m, int n) {
        vector<vector<int> > res(m,vector<int>(n,0));
        if(m==1||n==1) return 1;
        int count=0;
        res[0][0]=0;
        res[0][1]=res[1][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-1>=0) res[i][j]+=res[i-1][j];
                if(j-1>=0) res[i][j]+=res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};
