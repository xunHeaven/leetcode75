class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int len=asteroids.size();
        vector<int> res;
        for(int i=0;i<len;i++)
        {
            int num=asteroids[i];
            while(1)
            {
                if(res.size()==0)
                {
                    res.push_back(num);
                    break;
                }
                if(res[res.size()-1]<0)
                {
                    res.push_back(num);
                    break;
                }
                else
                {
                    if(num>0)
                    {
                        res.push_back(num);
                        break;
                    }
                    else if(num<0)
                    {
                        int temp=num*(-1);
                        if(res[res.size()-1]==temp)
                        {
                            res.pop_back();
                            break;
                        }
                        else if(res[res.size()-1]>temp)
                        {
                            break;
                        }
                        else
                        {
                            res.pop_back();
                        }
                    }
                }
            }
            

        }
        return res;
    }
};
