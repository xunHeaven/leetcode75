//解题思路：https://leetcode.cn/problems/equal-row-and-column-pairs/solutions/2298652/javapython3ha-xi-biao-cun-chu-shu-zi-xu-j1a4t
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int len =grid.size();
        int count=0;
        map<vector<int>,int> rowMap;//将grid的行作为map的键
        for(auto row:grid)
        {
            rowMap[row]++;//记录每行出现的次数，是否有重复的行
        }
        vector<int> col;
        for(int i=0;i<len;i++)
        {
            vector<int> col;
            for(int j=0;j<len;j++)
            {
                col.emplace_back(grid[j][i]);
            }
            count+=rowMap[col];//存在col键则加出现的次数，否则加0
        }
        return count;
    }
};
