#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
int visited[200005];
int depth[200005];
int highestancestor[200005];
int dep = 1;
int puukaaretjuuresta = 0;
set<int> answers;

void dfs(int s, int parent){
    visited[s]=1;
    depth[s]=dep;
    highestancestor[s]=dep;
    dep++;
    for(auto u : graph[s]){
        if(u!=parent){
            if(visited[u]==1){
                highestancestor[s]=min(highestancestor[s],depth[u]);
            }else{
                if(s==1)
                    puukaaretjuuresta+=1;
                dfs(u,s);
                highestancestor[s]=min(highestancestor[s],highestancestor[u]);
                if(highestancestor[u]>=depth[s] && s!=1){
                    answers.insert(s);
                }
            }
        }
    }
    if(s==1 && puukaaretjuuresta>=2){
        answers.insert(1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1,0);

    int n2=answers.size();
    cout << n2 << "\n";
    for(auto c : answers){
        cout << c << " ";
    }
}