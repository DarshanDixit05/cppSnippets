#include <bits/stdc++.h>
using namespace std;
#define ll   long long

    bool topoSortF(int V, vector<vector<int>>& arr) {
        vector<int>adj[V];
        for(auto it : arr)
        {
            adj[it[0]].push_back(it[1]);
        }

        int inDeg[V];
        for(int i=0; i<V; i++)inDeg[i]=0;
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])inDeg[it]++;
        }

        queue<int>q;
        for(int i=0; i<V; i++)
        {
            if(inDeg[i]==0)q.push(i);
        }
        vector<int>topoSort; //order
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for(auto it : adj[node])
            {
                inDeg[it]--;
                if(inDeg[it]==0)q.push(it);
            }
        }
        
        if(topoSort.size()==V)return true;
        return false;

    }
int main()
{
    return 0;
}


