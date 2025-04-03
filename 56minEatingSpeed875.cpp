class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long max_v=0;
        for(auto i:piles)
        {
            max_v=max(max_v,(long long)i);
        }
        long long left=1,right=max_v;
        while(left<=right)
        {
            long long mid=(left+right)/2;
            long long time=0;
            for(auto i:piles)
            {
                if(i%mid!=0)
                {
                    time+=(i/mid)+1;
                }
                else
                {
                    time+=i/mid;
                }
            }
            if(time>h)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        return right+1;
    }
};
