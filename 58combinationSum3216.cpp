class Solution {
public:
    void dfs(vector<vector<int>> &res1,vector<int> temp1,int k,int n,int index,int count)
    {
        if(temp1.size()==k&&count==n)
        {
            res1.push_back(temp1);
            return;
        }
        if(temp1.size()==k&&count!=n)
        {
            return;
        }
        if(index==10)
        {
            return;
        }
        for(int i=index;i<=9;i++)
        {
            if(n-(i+count)>=0)
            {
                vector<int> temp2=temp1;
                temp2.push_back(i);
                int newcount=count+i;

                dfs(res1,temp2,k,n,i+1,newcount);

            }
            else
            {
                return;
            }
            

        }

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        int min=0,max=0;
        if(k>0)
        {
            for(int i=1;i<=k;i++)
            {
                min+=i;
                max+=9-i+1;
            }
            if(n<min||n>max)
            {
                return res;
            }
            
        }
        vector<int> temp;
        int index=1,count=0;
        dfs(res,temp,k,n,index,count);
        return res;
    }
};
