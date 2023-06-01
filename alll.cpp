// #include<bits/stdc++.h>
// using namespace std;

// class Solution{
//     public: 
//     vector<int>bfsGraph(int V, vector<int>adj[]){
//         vector<int>vis(V+1,0);
//         vector<int>ans;

//         queue<int>q;
//         q.push(0);
//         vis[0]=1;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             ans.push_back(node);
//             for(auto it: adj[node]){
//                 if(!vis[it]){
//                     q.push(it);
//                     vis[it]=1;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// void addEdge(int u, int v, vector<int>adj[]){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void printAns(vector<int>&ans){
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }cout<<endl;
// }

// int main(){

// vector<int> adj[5];
// addEdge(0,1,adj);
// addEdge(0,2,adj);
// addEdge(0,3,adj);
// addEdge(2,4,adj);

// Solution obj;
// vector<int>ans = obj.bfsGraph(5,adj);
// printAns(ans);
// return 0;
// }







// DFS
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
    {
        storeDfs.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, storeDfs);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> storeDfs;
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
                dfs(i, vis, adj, storeDfs);
        }
        return storeDfs;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<int> adj[6];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 1);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 4, 2);
    addEdge(adj, 5, 1);
    Solution obj;
    vector<int> df;
    df = obj.dfsOfGraph(5, adj);
    for (auto it : df)
        cout << it << " ";

    return 0;
}