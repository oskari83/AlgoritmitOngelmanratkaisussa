#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[60005];
int status[60005];
bitset<60005> bset[60005];
vector<int> topoOrder;

void dfs(int s){
    if(status[s]==1 || status[s]==2)
        return;
    status[s]=1;
    for(auto u : graph[s]){
        dfs(u);
    }
    status[s]=2;
    topoOrder.push_back(s);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    int answers[60005];

    for(int i=0; i<m; i++){
        ll a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for(int i=1;i<n+1;i++){
        if(status[i]==0)
            dfs(i);
    }

    int n2=topoOrder.size();
    for(int i=0;i<n2;i++){
        bset[topoOrder[i]][topoOrder[i]]=1;
        for(auto u : graph[topoOrder[i]]){
            bset[topoOrder[i]]=bset[topoOrder[i]]|bset[u];
       }
       answers[topoOrder[i]]=bset[topoOrder[i]].count();
    }
    
    for(int i=1;i<n+1;i++){
        cout << answers[i] << " ";
    }
}