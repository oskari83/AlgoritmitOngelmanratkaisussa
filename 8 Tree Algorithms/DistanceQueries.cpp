#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
int ancestor[200005][31];
int depth[200005];
int n,q, ans;

void dfs(int n, int d, int prev){
    int nwD = d+1;
    depth[n]=nwD;
    for(auto u : graph[n]){
        if(u!=prev){
            ancestor[u][1]=n;
            dfs(u,nwD,n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int n1,n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    dfs(1,0,0);

    ancestor[1][1]=1;
    ancestor[0][1]=1;
    for(int i=2;i<31;i++){
        ancestor[1][i]=1;
        ancestor[0][i]=1;
        for(int j=2;j<n+1;j++){
            ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin >> a >> b;
        int l1 = depth[a];
        int l2 = depth[b];
        int aCur = a;
        int bCur = b;
        if(l1>l2){
            int delta = l1-l2;
            for(int i=29;i>=0;i--){
                if(delta>>i&1)
                    aCur=ancestor[aCur][i+1];
            }
        }else if(l2>l1){
            int delta = l2-l1;
            for(int i=29;i>=0;i--){
                if(delta>>i&1)
                    bCur=ancestor[bCur][i+1];
            }
        }

        if(aCur==bCur){
            ans = depth[a]+depth[b]-2*depth[aCur];
            cout << ans << "\n";
            continue;
        }

        for(int i=29;i>=0;i--){
            if(ancestor[aCur][i]!=ancestor[bCur][i]){
                aCur = ancestor[aCur][i];
                bCur = ancestor[bCur][i];
            }
        }
        aCur = ancestor[aCur][1];
        ans = depth[a]+depth[b]-2*depth[aCur];
        cout << ans << "\n";
    }
}