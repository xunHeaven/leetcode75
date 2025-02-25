class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len=flowerbed.size();
        int plate=0;
        if(len==1)
        {
            if(flowerbed[0]==0)
                {
                    plate++;
                    flowerbed[0]=1;
                }
        }
        else if(len==2)
        {
            if(flowerbed[0]==0&&flowerbed[1]==0)
            {
                {
                    plate++;
                    flowerbed[0]=1;
                }
            }
        }
        else
        {
            for(int i=0;i<len;i++)
        {
            if(i==0)
            {
  
                if(flowerbed[i]==0&&flowerbed[i+1]==0)
                {
                    plate++;
                    flowerbed[i]=1;
                }
            }
            else if(i==len-1)
            {
                if(flowerbed[i]==0&&flowerbed[i-1]==0)
                {
                    plate++;
                    flowerbed[i]=1;
                }
            }
            else{
                if(flowerbed[i]==0&&flowerbed[i-1]==0&&flowerbed[i+1]==0)
                {
                    plate++;
                    flowerbed[i]=1;
                }
            }
        }
        }
        if(plate>=n)
        {
            return true;
        }
        return false;
        
    }
};
