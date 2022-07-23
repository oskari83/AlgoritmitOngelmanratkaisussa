#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
int visited[200005];
int depth[200005];
int highestancestor[200005];
int dep = 1;
vector< pair<int,int> > answers;

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
                dfs(u,s);
                highestancestor[s]=min(highestancestor[s],highestancestor[u]);
                if(highestancestor[u]>depth[s]){
                    answers.push_back(make_pair(s,u));
                }
            }
        }
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
    for(int i=0;i<n2;i++){
        cout << answers[i].first << " " << answers[i].second << "\n";
    }
}