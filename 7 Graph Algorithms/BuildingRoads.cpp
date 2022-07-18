#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int visited[100005];
vector<int> graph[100005];

void dfs(int s) {
    if (visited[s]==1) 
        return;
    visited[s] = 1;
    for (auto u: graph[s]) {
        dfs(u);     
    }
}

int main() {
    int n,m;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    for(int i=0;i<n+1;i++){
        visited[i]=0;
    }

    vector<int> bridgesTo;
    int comps=0;
    int p=1;
    while(p<n+1){
        if(visited[p]==0){
            comps+=1;
            bridgesTo.push_back(p);
            dfs(p);
        }
        p+=1;
    }
    cout << comps-1 << "\n";
    int n2=bridgesTo.size();
    for(int i=1;i<n2;i++){
        cout << bridgesTo[0] << " " << bridgesTo[i] << "\n";
    }
}