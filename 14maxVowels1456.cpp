class Solution {
public:
    int maxVowels(string s, int k) {
        int len=s.size();
        vector<int> vowLoc;
        
        int countI_=0;
        int maxCount=0;
        //先固定一个大小为k的窗口
        if(k<len)
        {
            for(int i=0;i<k;i++)
            {
                if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
                {
                    countI_++;
                }
            }
            maxCount=countI_;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if((s[i]=='a')||(s[i]=='e')||(s[i]=='i')||(s[i]=='o')||(s[i]=='u'))
                {
                    countI_++;
                }
            }
            return countI_;
        }
        //滑动窗口每次右移动一格，如果刚释放的单元格存的是元音字母，则countI_--
        //如果新加入的单元格存储的是元音字母，则countI_++；
        //最后每次移动都要比较当前的countI_和maxCount的大小
        for(int i=1;i<=len-k;i++)
        {
            if((s[i-1]=='a')||(s[i-1]=='e')||(s[i-1]=='i')||(s[i-1]=='o')||(s[i-1]=='u'))
            {
                countI_--;
            }
            if((s[i+k-1]=='a')||(s[i+k-1]=='e')||(s[i+k-1]=='i')||(s[i+k-1]=='o')||(s[i+k-1]=='u'))
            {
                countI_++;
            }
            if(countI_>maxCount)
            {
                maxCount=countI_;
            }
            
        }
       
        return maxCount;

    }
};
