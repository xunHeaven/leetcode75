class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occur;//记录数字出现次数，键为数字，值为出现次数
        for(auto num:arr)
        {
            occur[num]++;
        }
        unordered_set<int> times;//统计次数的次数
        for(auto x:occur)
        {
            times.insert(x.second);
        }
        return times.size()==occur.size();

    }
};
