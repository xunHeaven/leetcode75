class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> vec(n-1,0);//路径是否访问过
        vector<vector<int>> vec1(n,vector<int>());//记录每个城市连接的路
        queue<int> que;//城市队列
        //que.emplace(0);
        int change=0;
        for(int i=0;i<n-1;i++)
        {
            vec1[connections[i][0]].emplace_back(i);
            vec1[connections[i][1]].emplace_back(i);
            
        }
        for(int i=0;i<vec1[0].size();i++)
        {

            vec[vec1[0][i]]=1;
            if(connections[vec1[0][i]][0]==0)
            {
                change++;
                que.emplace(connections[vec1[0][i]][1]);
            }
            else
            {
                que.emplace(connections[vec1[0][i]][0]);
            }

        }

        while(que.size())
        {
            int temp=que.front();
            que.pop();
            for(int i=0;i<vec1[temp].size();i++)
            {
                if((vec[vec1[temp][i]]==0))
                {
                    vec[vec1[temp][i]]=1;
                    if(connections[vec1[temp][i]][0]==temp)
                    {
                        change++;
                        que.emplace(connections[vec1[temp][i]][1]);
                    }
                    else
                    {
                        que.emplace(connections[vec1[temp][i]][0]);
                    }
                }
            }
            
        }
        return change;
    }
};
