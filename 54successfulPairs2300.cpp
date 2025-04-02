class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> pairs;
        int n=spells.size();
        int m=potions.size();
        for(int i=0;i<spells.size();i++)
        {
            int left=0,right=m-1;
            if((long long)spells[i]*potions[left]>=success)
            {
                pairs.emplace_back(m);
                continue;
            }
            if((long long)spells[i]*potions[right]<success)
            {
                pairs.emplace_back(0);
                continue;
            }

            
            while(left<=right)
            {
                int mid=(left+right)/2;
                long long temp=(long long)spells[i]*potions[mid];
                if(temp<success)
                {

                    left=mid+1;

                }
                else
                {
                    right=mid-1;
                }
            }
            if((long long)spells[i]*potions[right]<success)
            {
                pairs.emplace_back(m-right-1);
            }
            else
            {
                pairs.emplace_back(m-right);
            }
        }
        return pairs;
    }
};
