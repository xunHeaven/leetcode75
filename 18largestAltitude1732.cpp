class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int len=gain.size();
        int maxH=0;
        int tempH=0;
        for(int i=0;i<len;i++)
        {
            tempH+=gain[i];
            maxH=max(maxH,tempH);
        }
        return maxH;
    }
};
