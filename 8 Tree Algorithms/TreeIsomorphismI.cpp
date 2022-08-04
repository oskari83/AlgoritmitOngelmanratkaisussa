#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

map<vector<int>,int> ids;
int level=0;
int t;

int dfs(int n, int prev, vector<int> graph[]){
    int childs = 0;
    vector<int> childList;
    for(auto u : graph[n]){
        if(u!=prev){
            childList.push_back(dfs(u,n,graph));
            childs++;
        }
    }
    sort(childList.begin(),childList.end());
    if(childs==0){
        return 1;
    }else{
        if(ids.count(childList)==0){
            ids[childList]=level++;
        }
        return ids[childList];
    }
}

int main() {
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
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
        int treeId = dfs(1,0,graph1);
        int treeId2 = dfs(1,0,graph2);
        if(treeId==treeId2){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}