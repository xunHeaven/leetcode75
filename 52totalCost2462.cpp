class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        //两个优先队列，分别保存最左边candidates个价格和最右边的candidates个价格
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int len=costs.size();
        int left=0;
        int right=len-1;
        long long res=0;
        while(k--)
        {
            //int i=1;
            while(pq1.size()<candidates&&(left)<=right)
            {
                pq1.emplace(costs[left]);
                left++;
            }
            //int j=1;
            while(pq2.size()<candidates&&(right)>=left)
            {
                pq2.emplace(costs[right]);
                right--;
            }
            if(pq1.size()==0&&pq2.size()==0)
            {
                return res;
            }
            if(pq1.size()!=0||pq2.size()!=0)
            {
                int minL=0;
                int minR=0;
                if(pq1.size()!=0)
                {
                    minL=pq1.top();
                }
                else
                {
                    minL=INT_MAX;
                }
                if(pq2.size()!=0)
                {
                    minR=pq2.top();
                }
                else
                {
                    minR=INT_MAX;
                }
                
                if(minL<=minR)
                {
                    res+=minL;
                    pq1.pop();
                }
                else
                {
                    res+=minR;
                    pq2.pop();
                }

            }
            
        }
        return res;
    }
};
