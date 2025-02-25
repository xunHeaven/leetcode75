class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        string word3;
        int len3=len1+len2;
        int j1=0;
        int j2=0;
        for(int i=0;i<len3;i++)
        {
            if((j1<len1)&&(i%2==0))
            {
                word3+=word1[j1];
                j1++;
            }
            else if((j2<len2)&&(i%2!=0))
            {
                word3+=word2[j2];
                j2++;
            }
            else{
                if(j1==len1)
                {
                    word3+=word2[j2];
                    j2++;
                }
                else if(j2==len2)
                {
                    word3+=word1[j1];
                    j1++;
                }
            }
            //cout<<word3[i]<<" "<<endl;
        }
        return word3;
    }
};
