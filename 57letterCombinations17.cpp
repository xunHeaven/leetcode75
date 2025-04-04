class Solution {
    string str1[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void dfs(string str[],vector<string>& res,string digits,int n,string temp)
    {
        if(n!=digits.size()-1)
        {
            if(digits[n]-'0'>=2&&digits[n]-'0'<=9)
            {
                int len1=str[digits[n]-'0'].size();
                for(auto i:str[digits[n]-'0'])
                {
                    string temp1=temp;
                    temp1.push_back(i);
                    dfs(str,res,digits,n+1,temp1);
                }
            }
            else{
                dfs(str,res,digits,n+1,temp);
            }
        }
        else
        {
            if(digits[n]-'0'>=2&&digits[n]-'0'<=9)
            {
                int len1=str[digits[n]-'0'].size();
                for(auto i:str[digits[n]-'0'])
                {
                    string temp1=temp;
                    temp1.push_back(i);
                    res.push_back(temp1);
                }
            }
            else{
                res.push_back(temp);
            }
            return;
        }
    }
    vector<string> letterCombinations(string digits) {
        int len=digits.size();
        vector<string> res;
        if(len==0)
        {
            return res;
        }
        string temp="";
        dfs(str1,res,digits,0,temp);
        return res;

    }
};
