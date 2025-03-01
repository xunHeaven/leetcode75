class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1=s.size();
        int len2=t.size();
        int j=0;
        if(len1==0)
        {
            return true;
        }
        for(int i=0;i<len2;i++)
        {
            if(t[i]==s[j])
            {
                if(j==len1-1)
                {
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};
