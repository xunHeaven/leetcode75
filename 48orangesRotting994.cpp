class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> vist(m*n,0);//记录节点是否访问过
        queue<pair<int,int>> que;//pair.first表示节点序号，pair.second表示第几分钟烂到他
        //先把初始烂橘子加入队列
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]==2)
                {
                    vist[i*n+j]=1;
                    que.emplace(i*n+j,0);
                }
            }
        }
        int timeCount=0;//计时
        int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//运动方向数组
        while(que.size())
        {
            int x=que.front().first/n;
            int y=que.front().first%n;
            int count=que.front().second;
            que.pop();
            for(auto dir:directions)
            {
                int x1=x+dir[0];
                int y1=y+dir[1];
                if((x+dir[0]>=0)&&(x+dir[0]<=m-1)&&(y+dir[1]>=0)&&(y+dir[1]<=n-1)&&(vist[x1*n+y1]==0)&&(grid[x1][y1]==1))
                {
                    vist[x1*n+y1]=1;
                    grid[x1][y1]=2;
                    que.emplace(x1*n+y1,count+1);
                    if(count+1>timeCount) timeCount=count+1;
                }
    
            }
        }
        //检测是否还有新鲜橘子
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                //vist[i*n+j]=1;
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return timeCount;


    }
};
