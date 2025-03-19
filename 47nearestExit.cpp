//解题思路：https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/solutions/2938271/javapython3cbfsxi-dai-e-wai-xin-xi-de-zu-xmnf
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        //为每个坐标设置唯一标识符index=y*col+x,如(0,0)=0,(1,2)=1*n+2
        queue<pair<int,int>>que;//pair.first为坐标标识符，
        //pair.second表示起点坐标到达当前坐标的路程。
        int directions[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//运动方向
        que.emplace(entrance[0]*n+entrance[1],0);//将起始节点入队；
        maze[entrance[0]][entrance[1]]='+';//将起始节点置为墙
        while(que.size())
        {
            auto q=que.front();
            que.pop();
            int x=q.first/n;
            int y=q.first%n;
            int d=q.second;
            for(auto dirc:directions)
            {
                //如果下一个可到的节点在边界，则可以直接返回结果
                if(((x+dirc[0]==0&&y+dirc[1]>=0&&y+dirc[1]<=n-1)||(x+dirc[0]==m-1&&y+dirc[1]>0&&y+dirc[1]<n-1)||(y+dirc[1]==0&&x+dirc[0]>=0&&x+dirc[0]<=m-1)||(y+dirc[1]==n-1&&x+dirc[0]>=0&&x+dirc[0]<=m-1))&&(maze[x+dirc[0]][y+dirc[1]]=='.'))
                {
                    return d+1;
                }
                //如果下一个可到节点不在边界，则加入队列
                if((x+dirc[0]>0&&x+dirc[0]<m-1&&y+dirc[1]>0&&y+dirc[1]<n-1))
                {
                    if(maze[x+dirc[0]][y+dirc[1]]=='.')
                    {
                        que.emplace((x+dirc[0])*n+y+dirc[1],d+1);
                        maze[x+dirc[0]][y+dirc[1]]='+';
                    }
                    
                }

            }
        }
        return -1;

    }
};
