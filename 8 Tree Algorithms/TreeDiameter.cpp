#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
int maxLen=0;
int maxLenNode;

void dfs(int s, int len, int prev) {
    for (auto u: graph[s]) {
        if(u!=prev)
            dfs(u,len+1,s);     
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
    dfs(1,0,0);
    
    dfs(maxLenNode,0,0);
    cout << maxLen << "\n";
}