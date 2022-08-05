#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

map<vector<int>,int> ids;
vector<int> tree1centroids;
vector<int> tree2centroids;
int level=0;
int nodes[2][200005];
int t,n;

void clearAll(){
    tree1centroids.clear();
    tree2centroids.clear();
}

int findTreeId(int n, int prev, vector<int> graph[]){
    vector<int> childList;
    for(auto u : graph[n]){
        if(u!=prev){
            childList.push_back(findTreeId(u,n,graph));
        }
    }
    sort(childList.begin(),childList.end());
    if(ids.count(childList)==0){
        ids[childList]=level;
        level++;
    }
    return ids[childList];
}

void dfs(int n, int prev, vector<int> adjGraph[],int id){
    int childNodes=0;
    for(auto u : adjGraph[n]){
        if(u!=prev){
            dfs(u,n,adjGraph,id);
            childNodes+=nodes[id][u]+1;
        }
    }
    nodes[id][n]=childNodes;
}

void dfs2(int n2, int prev, int totalNodes,vector<int> adjGraph[], int id){
    bool check = true;
    for(auto u : adjGraph[n2]){
        if(u!=prev){
            dfs2(u,n2,totalNodes,adjGraph,id);
            if(nodes[id][u]+1>totalNodes/2){
                check=false;
            }
        }
    }
    if(totalNodes-nodes[id][n2]-1>(totalNodes/2)){
        check=false;
    }
    if(check){
        if(id==0){
            tree1centroids.push_back(n2);
        }else{
            tree2centroids.push_back(n2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
 
    for(int i=0;i<t;i++){
        cin >> n;
        clearAll();
        vector<int> graph1[n+1];
        vector<int> graph2[n+1];
        for(int j=0;j<n-1;j++){
            int a,b;
            cin >> a >> b;
            graph1[a].push_back(b);
            graph1[b].push_back(a);
        }
 
        for(int j=0;j<n-1;j++){
            int a,b;
            cin >> a >> b;
            graph2[a].push_back(b);
            graph2[b].push_back(a);
        }
 
        dfs(1,0,graph1,0);
        dfs(1,0,graph2,1);
        dfs2(1,0,n,graph1,0);
        dfs2(1,0,n,graph2,1);
 
        vector<int> tree2ids;
        vector<int> tree1ids;
 
        for(auto v : tree1centroids){
            int temp = findTreeId(v,0,graph1);
            tree1ids.push_back(temp);
        }
        for(auto v : tree2centroids){
            int temp = findTreeId(v,0,graph2);
            tree2ids.push_back(temp);
        }
        bool found = false;
        for(auto p : tree1ids){
            for(auto k : tree2ids){
                if(p==k){
                    cout << "YES" << "\n";
                    found=true;
                    break;
                }
            }
            if(found)
                break;
        }
        if(!found){
            cout << "NO" << "\n";
        }
    }
}