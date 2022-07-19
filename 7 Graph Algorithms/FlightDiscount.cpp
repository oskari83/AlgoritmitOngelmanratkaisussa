#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    cin >> n >> m;
    vector< pair<ll,ll> > graph[n+1];

    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    ll distance[n+1][2];
    distance[1][0]=0;
    distance[1][1]=0;
    for(int i=2;i<=n;i++){
        distance[i][0]=1e18+7;
        distance[i][1]=1e18+7;
    }

    priority_queue< vector<ll> > q;

    vector<ll> t3;
    t3.push_back(0); t3.push_back(1); t3.push_back(0);

    q.push(t3);
    while(!q.empty()){
        vector<ll> vec = q.top();
        ll dist = -vec[0];
        ll node = vec[1];
        int type = vec[2];
        q.pop();
        if(dist!=distance[node][type])
            continue;
        if(node==n)
            break;
        
        for(auto u : graph[node]){
            if(type!=1){
                ll curUnused = distance[u.first][0];
                ll newdist = distance[node][0]+u.second;
                if(newdist<curUnused){
                    distance[u.first][0]=newdist;
                    vector<ll> tmp;
                    tmp.push_back(-newdist); tmp.push_back(u.first); tmp.push_back(0);
                    q.push(tmp);
                }
            }

            ll curUsed = distance[u.first][1];
            ll newDistuseNow = distance[node][0]+(u.second/2);
            ll newUsed = distance[node][1]+u.second;
            ll usedMin = min(newDistuseNow,newUsed);
            if(usedMin<curUsed){
                distance[u.first][1]=usedMin;
                vector<ll> tmp2;
                tmp2.push_back(-usedMin); tmp2.push_back(u.first); tmp2.push_back(1);
                q.push(tmp2);
            }
        }
    }

    cout << distance[n][1];
}