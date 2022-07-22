#include <iostream>
using namespace std;
typedef long long ll;

int visited[200005];
int distance2[200005];
int succ[200005][31];

void dfs(int s){
    if(visited[s]==1)
        return;
    visited[s]=1;
    dfs(succ[s][1]);
    distance2[s]=distance2[succ[s][1]]+1;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n,q;
    cin >> n >> q;
    for(int i=1;i<n+1;i++){
        cin >> succ[i][1];
    }

    for(int j=2;j<31;j++){
        for(int i=1;i<n+1;i++){
            succ[i][j]=succ[succ[i][j-1]][j-1];
        }
    }

    for(int i=1;i<n+1;i++){
        if(visited[i]!=1)
            dfs(i);
    }

    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;

        int cycleNode = x;
        int k = distance2[x];
        for(int i=29;i>=0;i--){
            if(k>>i&1)
                cycleNode=succ[cycleNode][i+1];
        }

        int x2 =x;
        int k2 = distance2[x]-distance2[y];
        for(int i=29;i>=0;i--){
            if(k2>>i&1)
                x2=succ[x2][i+1];
        }

        int x3 = cycleNode;
        int k3 = distance2[cycleNode]-distance2[y];
        for(int i=29;i>=0;i--){
            if(k3>>i&1)
                x3=succ[x3][i+1];
        }
        
        if(x2==y){
            cout << k2 << "\n";
        }else if(x3==y){
            cout << k3 + k << "\n";
        }else{
            cout << -1 << "\n";
        }
    }
}