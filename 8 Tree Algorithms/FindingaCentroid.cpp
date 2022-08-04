#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
int nodes[200005];
int isCentroid[200005];
int nnn;

void dfs(int n, int prev){
    int childNodes=0;
    for(auto u : graph[n]){
        if(u!=prev){
            dfs(u,n);
            childNodes+=nodes[u]+1;
        }
    }
    nodes[n]=childNodes;
}

void dfs2(int n, int prev){
    bool check = true;
    for(auto u : graph[n]){
        if(u!=prev){
            if(nodes[u]+1>nnn/2)
                check=false;
    
            dfs2(u,n);
        }else{
            int nodesUp = nodes[1]-nodes[n];
            if(nodesUp>nnn/2)
                check=false;
        }
    }
    if(check)
        isCentroid[n]=1;
}

int main() {
    cin >> nnn;
    for(int i=1;i<nnn;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<nnn+1;i++){
        if(isCentroid[i]==1){
            cout << i << "\n";
            break;
        }
    }
}