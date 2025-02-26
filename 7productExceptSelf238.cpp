class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftV(n,1);
        vector<int> rightV(n,1);
        int leftTem=1;
        int rightTem=1;
        int j=n-1;
        for(int i=0;i<n;i++)
        {
            leftV[i]=leftTem;
            leftTem*=nums[i];
            rightV[j]=rightTem;
            rightTem*=nums[j];
            j--;
        }
        vector<int> res(n,1);
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                res[i]=rightV[i];
            }
            else if(i==n-1)
            {
                res[i]=leftV[i];
            }
            else{
                res[i]=leftV[i]*rightV[i];
            }
        }
        return res;
    }
};
