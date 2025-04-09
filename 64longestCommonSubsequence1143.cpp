class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector< vector<int> > res(m,vector<int> (n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(text1[i]==text2[j])
                {
                    if(i-1>=0&&j-1>=0)
                    {
                        res[i][j]=res[i-1][j-1]+1;
                    }
                    else
                    {
                        res[i][j]=1;
                    }
                }
                else{
                    if(i-1>=0)
                    {
                        res[i][j]=res[i-1][j];
                    }
                    if(j-1>=0)
                    {
                        res[i][j]=max(res[i][j],res[i][j-1]);
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};
