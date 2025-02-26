class Solution {
public:
    string reverseWords(string s) {
        vector<string> getWord;
        int len=s.size();
        string str1;
        int index=0;
        int count=0;
        int loc=0;
        for(int i=0;i<len;i++)
        {
            if((index==0)&&(s[i]!=' '))
            {
                index=1;
                loc=i;
                count++;
                if(i==len-1)
                {
                    str1=s.substr(loc,count);
                    getWord.push_back(str1);
                    count=0;
                }
            }
            else if((index==1)&&(s[i]==' '||i==len-1))
            {
                index=0;
                if(i==len-1&&s[i]!=' ')
                {
                    count++;
                }
                str1=s.substr(loc,count);
                getWord.push_back(str1);
                count=0;
            }
            else if(index==1&&s[i]!=' ')
            {
                count++;
            }

        }
        string str2;
        for(int i=getWord.size()-1;i>=0;i--)
        {
            if(i!=0)
            {
                str2+=getWord[i];
                str2+=' ';
            }
            else
            {
                str2+=getWord[i];
            }
        }
        return str2;
    }
};
