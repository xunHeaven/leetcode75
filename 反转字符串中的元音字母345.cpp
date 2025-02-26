class Solution {
public:
    string reverseVowels(string s) {
        string Yuan="AEIOUaeiou";
        int len1=s.size();
        int len2=Yuan.size();
        string s1;
        vector<int> isYuan;
        for(int i=0;i<len1;i++)
        {
            int index=0;
            for(int j=0;j<len2;j++)
            {
                if(s[i]==Yuan[j])
                {
                    index=1;
                    break;
                }
            }
            if(index==1)
            {
                s1+=s[i];
            }
            isYuan.push_back(index);

        }
        string s2;
        int k=s1.size()-1;

        for(int i=0;i<len1;i++)
        {
            if(isYuan[i]==0)
            {
                s2+=s[i];
            }
            else
            {
                s2+=s1[k];
                k--;
            }
        }
        return s2;
        
    }
};
