#include <algorithm>
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1=str1.size();
        int len2=str2.size();
        int j=0;
        // 假设str1是N个x，str2是M个x，那么str1+str2肯定是等于str2+str1的。
        if((str1+str2 != str2+str1)||(len1==0)||(len2==0))
        {
            return "";
        }
        else
        {
            int minlen=min(len1,len2);
            //从公因子串能选的最大长度试起
            for(j=minlen;j>0;j--)
            {
                if((len1%j==0)&&(len2%j==0))
                {
                    //return str1.substr(0,j);
                    break;
                }
            }
        }
        return str1.substr(0,j);
    }
};
