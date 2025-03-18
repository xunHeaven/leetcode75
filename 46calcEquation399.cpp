//解题思路：https://leetcode.cn/problems/evaluate-division/solutions/2539446/javapython3cyan-du-you-xian-sou-suo-jian-uwy3
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //存储equations中节点之间的运算结果
        unordered_map<string,unordered_map<string,double>> graph;
        string node1;
        string node2;
        double val1;
        for(int i=0;i<equations.size();i++)
        {
            node1=equations[i][0];
            node2=equations[i][1];
            val1=values[i];
            graph[node1][node2]=val1;
            graph[node1][node1]=1.0;
            graph[node2][node1]=1.0/val1;
            graph[node2][node2]=1.0;

        }
        int n=queries.size();
        queue<pair<string,double>> que;//广度优先搜索队列
        vector<double> res(n,-1.0);//存储计算结果
        for(int i=0;i<n;i++)
        {
            node1=queries[i][0];
            node2=queries[i][1];
            if(graph.find(node1)==graph.end()||graph.find(node2)==graph.end())
            {
                continue;//如果节点在我们的图中没有出现过，直接跳过处理
            }
            que.emplace(node1,1.0);
            unordered_set<string> visited{node1};//存储访问过的节点
            while(!que.empty())
            {
                string q1=que.front().first;
                double mul=que.front().second;
                que.pop();
                for(pair<string,double> x:graph[q1])//遍历q1的邻接节点
                {
                    string ngh=x.first;
                    double weight=x.second;
                    if(ngh==node2)
                    {
                        res[i]=mul*weight;
                        //queue<pair<string,double>> tempq;
                        //swap(que,tempq);
                        break;
                    }
                    if(visited.find(ngh)==visited.end())
                    {
                        visited.emplace(ngh);
                        que.emplace(ngh,mul*weight);
                    }
                }
            }


        }
        return res;

    }
}; 
