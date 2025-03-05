class RecentCounter {
public:
    RecentCounter() {
        
    }
    queue<int> que;
    int ping(int t) {
        que.push(t);
        while(que.front()<t-3000)
        {
            que.pop();
        }
        return que.size();

    }
};
