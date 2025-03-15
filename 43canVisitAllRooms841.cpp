class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vec(n,0);
        vec[0]=1;
        queue<int> que;
        que.emplace(0);
        
        while(que.size()>0)
        {
            int room=que.front();
            que.pop();
            for(auto& x:rooms[room])
            {
                if(vec[x]==0)
                {
                    que.emplace(x);
                    vec[x]=1;
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=vec[i];
        }
        if(sum==n)
        {
            return true;
        }
        return false;

    }
};
