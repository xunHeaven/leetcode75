class Solution {
public:
    void adjustHeap(vector<int> &a,int i,int heapSize)
    {
        int left=i*2+1;//i的左子节点在数组中的位置
        int right=i*2+2;//i的右子节点在数组中的位置
        int largest=i;//存放i和其子节点的最大节点的编号，初始化为i
        //如果左子节点存在，且大于最大节点，则更换最大节点编号
        if(left<heapSize&&a[left]>a[largest])largest=left;
        //如果右子节点存在，且大于最大节点，则更换最大节点编号
        if(right<heapSize&&a[right]>a[largest])largest=right;
        //如果最大节点不是当前节点，将当前节点的值与最大节点的值进行交换
        if(largest!=i)
        {
            swap(a[i],a[largest]);
            //交换之后，处理对应子节点为根节点的树,相当于是从上到下调整
            adjustHeap(a,largest,heapSize);
        }

    }
    void buildMaxHeap(vector<int>& a,int heapSize)
    {
        //从最后一个非叶子节点开始处理
        for(int i=(heapSize/2)-1;i>=0;i--)
        {
            //这个循环虽是从下到上，可是adjustHeap()自身的递归却是从上到下
            adjustHeap(a,i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize=nums.size();
        //构建大根堆
        buildMaxHeap(nums,heapSize);
        //k=1不用处理（堆顶元素最大），k=2处理一次
        for(int i=nums.size()-1;i>=nums.size()-k+1;i--)
        {
            //交换堆顶元素和可调整堆的最后一个元素
            swap(nums[0],nums[i]);
            //可调整的堆长度减一，相当于把交换了的堆顶元素舍去。
            heapSize--;
            //把当前堆调整为大根堆
            adjustHeap(nums,0,heapSize);
        }
        return nums[0];

    }
};
