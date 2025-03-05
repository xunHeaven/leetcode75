class Solution {
public:
    string decodeString(string s) {
         stack<int> nums;
         stack<string> res;
         string tempS="";
         int num=0;

         for(auto c:s)
         {
            if(c>='0'&&c<='9')
            {
                num=num*10+(c-'0');
            }
            else if(c>='a'&&c<='z')
            {
                tempS+=c;
            }
            else if(c=='[')
            {
                nums.push(num);
                res.push(tempS);
                tempS="";
                num=0;
            }
            else if(c==']')
            {
                int times=nums.top();
                nums.pop();
                for(int i=0;i<times;i++)
                {
                    res.top()+=tempS;
                }
                tempS=res.top();
                res.pop();

            }
         }
         return tempS;
    }
};
