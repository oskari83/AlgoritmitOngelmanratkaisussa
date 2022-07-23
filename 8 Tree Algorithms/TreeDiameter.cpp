#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int visited[200005];
vector<int> graph[200005];
int maxLen=0;
int maxLenNode;

void dfs(int s, int len) {
    if (visited[s]==1) 
        return;
    visited[s] = 1;
    for (auto u: graph[s]) {
        dfs(u,len+1);     
    }
    if(len>maxLen){
        maxLen=len;
        maxLenNode=s;
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=0;i<n-1;i++){
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    dfs(1,0);
    for(int i=1;i<n+1;i++){
        visited[i]=0;
    }
    
    dfs(maxLenNode,0);
    cout << maxLen << "\n";
}