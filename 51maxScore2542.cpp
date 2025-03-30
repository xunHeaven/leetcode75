class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int len=nums1.size();
        vector<int> idxes(len);//生成索引
        for(int i=0;i<len;i++)
        {
            idxes[i]=i;
        }
        //按照num2中的大小，对索引单独进行排序
        sort(idxes.begin(),idxes.end(),[&](int i,int j){
            return nums2[i]>nums2[j];
        });
        //优先队列实现小根堆
        priority_queue<int,vector<int>,greater<int>>pq;
        //nums1中选出来的元素和·
        long long sum=0;
        for(int i=0;i<k;i++)
        {
            int idex=idxes[i];
            sum+=nums1[idex];
            pq.emplace(nums1[idex]);
        }
        //分数结果进行初始化,nums2[indxes[k-1]]是选中的k个序号中，对应nums的最小值
        long long res=sum*nums2[idxes[k-1]];
        //从k开始，找到最后一个元素，计算最大分数
        for(int i=k;i<len;i++)
        {
            int idex=idxes[i];
            if(nums1[idex]>pq.top())
            {
                sum+=nums1[idex]-pq.top();
                pq.pop();
                pq.emplace(nums1[idex]);
                res=max(res,sum*nums2[idex]);
            }
        }
        return res;

    }
};
