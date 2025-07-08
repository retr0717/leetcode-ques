#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Position this line where user code will be pasted.
class Solution {
  private:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &stack)
    {
        visited[node] = 1;
        
        for(auto it: adj[node])
        {
            if(!visited[it])
                dfs(it, visited, adj, stack);
        }
        
        stack.push(node);
    }
    
    void dfs3(int node, vector<int> &visited, vector<int> adjRev[])
    {
        visited[node] = 1;
        
        for(auto it: adjRev[node])
        {
            if(!visited[it])
                dfs3(it, visited, adjRev);
        }
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        //sorting based on finishing time.
        int size = adj.size();
        vector<int> visited(size, 0);
        stack<int> stack;
        
        for(int i = 0 ; i < size ; i++)
        {
            if(!visited[i])
                dfs(i, visited, adj, stack);
        }
        
        //reverse the directed graph.(transpose).
        vector<int> adjRev[size];
        for(int i = 0 ; i < size ; i++)
        {
            visited[i] = 0;
            for(auto it: adj[i])
            {
                adjRev[it].push_back(i);
            }
        }
        
        //do the dfs based using the stack order.
        int scc = 0;
        while(!stack.empty())
        {
            int node = stack.top();
            stack.pop();
            
            if(!visited[node])
            {
                //compute the no of strongly connected components.
                scc++;
                dfs3(node, visited, adjRev);
            }
        }
        
        return scc;
    }
}
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
B
B
B
B
B
B
B
B
B
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
B
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
A
};
