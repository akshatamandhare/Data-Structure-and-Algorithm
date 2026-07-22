#include<bits/stdc++.h>
using namespace std;

class disjointset{
    private:
    vector<int> rank, size, parent;
    public: 
    disjointset(int n){
        rank.resize(n+1, 0);
        size.resize(n+1);
        parent.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }

    void rankBySize(int u, int v){
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    disjointset ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"Same parent";
    }
    else{
        cout<<"Not same";
    }

    
    ds.unionByRank(3, 7);

    cout<<endl;
    if(ds.findPar(3) == ds.findPar(7)){
        cout<<"Same parent";
        cout<<endl;
    }
    else{
        cout<<"Not same";
    }
    return 0;
}