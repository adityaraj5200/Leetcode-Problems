// Approach:
// 1. Use Union-Find (DSU) to group the c stations (1…c) into connected components based on connections.
// 2. For each component maintain a min-heap (priority queue) of **online** station IDs so that when a station goes offline we can still find the smallest online one quickly.
// 3. Maintain an array online[] to track if station x is currently online.
// 4. Process queries in order:
//    - If query is [1,x]: if x is online return x; else find component root of x and pop from its heap until we see an online station (or heap is empty) and return that ID or -1.
//    - If query is [2,x]: mark online[x]=false.
// TC: O((c + connections + queries) * α(c) + Q * log(c)) ~ O((c + n + q) log c) worst‐case.
// SC: O(c + n) for DSU + heaps.

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> parent, sz;
    // Constructor: initializes DSU for n nodes
    DSU(int _n) {
        n = _n;
        parent.resize(n + 1);
        sz.assign(n + 1, 1);  // each set initially has size 1
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;    // each node is its own parent initially
        }
    }

    int find(int x){ 
        return parent[x]==x ? x : parent[x]=find(parent[x]);
    }
    
    void unite(int x,int y){
        x=find(x); y=find(y);
        if(x==y) return;
        if(sz[x]<sz[y]) swap(x,y);
        parent[y]=x; sz[x]+=sz[y];
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for(auto &e:connections){
            int u=e[0], v=e[1];
            dsu.unite(u,v);
        }
        vector<bool> online(c+1,true);
        // componentMinHeap[root] holds min-heap of station IDs initially online
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> componentMinHeap;
        for(int i=1;i<=c;++i){
            int r=dsu.find(i);
            componentMinHeap[r].push(i);
        }
        vector<int> res;
        res.reserve(queries.size());
        for(auto &q:queries){
            int op=q[0], x=q[1];
            if(op==1){
                if(online[x]){
                    res.push_back(x);
                } else {
                    int r=dsu.find(x);
                    auto &heap = componentMinHeap[r];
                    while(!heap.empty() && !online[heap.top()]){
                        heap.pop();
                    }
                    if(heap.empty()) res.push_back(-1);
                    else res.push_back(heap.top());
                }
            } else if(op==2){
                online[x]=false;
            }
        }
        return res;
    }
};
