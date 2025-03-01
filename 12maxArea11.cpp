class Solution {
public:
//参考题解https://leetcode.cn/problems/container-with-most-water/solutions/94102/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu
    int maxArea(vector<int>& height) {
        int len=height.size();
        int i=0,j=len-1;
        int maxV=0;//存储最大容积
        int tempV=0;//暂存每次计算的容积
        while(i!=j)
        {
            if(height[i]<height[j])
            {
                tempV=height[i]*(j-i);
                i++;
            }
            else
            {
                tempV=height[j]*(j-i);
                j--;
            }
            if(tempV>maxV)
            {
                maxV=tempV;
            }
        }
        return maxV;
    }
};
