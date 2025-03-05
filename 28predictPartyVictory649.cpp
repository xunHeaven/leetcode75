class Solution {
public:
    bool win(string senate,char winner )
    {
        for(auto c:senate)
        {
            if(c!=winner)
            {
                return false;
            }
        }
        return true;
    }
    string predictPartyVictory(string senate) {
        queue<char> que;
        while(1)
        {
            int i=0;
            while(i<senate.size())
            {
                if(que.size()==0)
                {
                    que.push(senate[i]);
                    i++;
                }
                else
                {
                    if(senate[i]==que.front())
                    {
                        que.push(senate[i]);
                        i++;
                    }
                    else
                    {
                        que.pop();
                        senate.erase(i,1);
                    }
                }
                
            }
            if( win(senate,'R'))
            {
                return "Radiant";
            }
            if( win(senate,'D'))
            {
                return "Dire";
            }
        }
        
      return "";  
    }
};
