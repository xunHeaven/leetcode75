class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        //如果s不为空，则返回s中的最小数，并把该数移除s
        if(s.size())
        {
            int temp=*s.begin();
            s.erase(s.begin());
            return temp;
        }
        //如果s为空，则返回cur，更新cur
        int temp=cur;
        cur++;
        return temp;
    }
    
    void addBack(int num) {
        //默认无限集里刚开始就有所有正整数。
        //如果当前要加入无限集的数大于cur，说明无限集里已经存在，不用操作
        //如果当前要加入无限集的数小于cur，说明该数已经从无限集里面删除过，加入到s中；
        if(num<cur)
        {
            s.emplace(num);
        }
    }
private:
    set<int> s;//存储小于cur，且被从无限集中删除又加入的元素
    int cur=1;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
