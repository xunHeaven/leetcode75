class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vec(n,0);
        int count=1;
        queue<int> que;
        que.emplace(0);
        while(que.size())
        {
            int temp=que.front();
            que.pop();
            if(vec[temp]==0)
            {
                vec[temp]=1;
                for(int j=0;j<n;j++)
                {
                    if(j!=temp&&isConnected[temp][j]==1)
                    {
                        que.emplace(j);
                    }
                }
            }

        }
        for(int i=1;i<n;i++)
        {
            if(vec[i]==0)
            {
                count++;
                que.emplace(i);
                while(que.size())
                {
                    int temp=que.front();
                    que.pop();
                    if(vec[temp]==0)
                    {
                        vec[temp]=1;
                        for(int j=0;j<n;j++)
                        {
                            if(j!=temp&&isConnected[temp][j]==1)
                        {
                        que.emplace(j);
                        }
                        }
                    }

                }
                
            }
        }
        return count;

    }
};
