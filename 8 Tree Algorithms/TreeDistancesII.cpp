#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
ll depth[200005];
ll sum[200005];
int n;

void dfs(int s, int prev, ll d) {
    sum[1]+=d;
    depth[s]=1;
    for(auto u: graph[s]) {
        if(u!=prev){
            dfs(u,s,d+1); 
            depth[s]+=depth[u];
        }
    }
}

void dfs2(int s, int prev) {
    for(auto u: graph[s]) {
        if(u!=prev){
            sum[u]=sum[s]+n-2*depth[u];
            dfs2(u,s); 
        }
    }
} 

int main() {
    cin >> n;

    for(int i=0;i<n-1;i++){
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    dfs(1,0,0);
    dfs2(1,0);
    for(int i=1;i<n+1;i++){
        cout << sum[i] << " ";
    }    
}