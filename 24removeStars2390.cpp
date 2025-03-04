class Solution {
public:
    string removeStars(string s) {
        string res;
        for(auto c:s)
        {
            if(c=='*')
            {
                if(res.size()>0)
                {
                    res.pop_back();
                }
            }
            else
            {
                res+=c;
            }
        }
        return res;
    }
};
