#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    cin >> n >> m;
    ll mod = 1e9+7;
    vector< pair<ll,ll> > graph[n+1];

    for(int i=0; i<m; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }

    ll distance[n+1][4];
    distance[1][0]=0;
    distance[1][1]=1;
    distance[1][2]=0;
    distance[1][3]=0;
    for(int i=2;i<=n;i++){
        distance[i][0]=1e18+7;
        distance[i][1]=0;
        distance[i][2]=1e18+7;
        distance[i][3]=0;
    }

    priority_queue< vector<ll> > q;

    vector<ll> t3;
    t3.push_back(0); t3.push_back(1);
    q.push(t3);

    while(!q.empty()){
        vector<ll> vec = q.top();
        ll dist = -vec[0];
        ll node = vec[1];
        q.pop();
        if(dist!=distance[node][0])
            continue;

        for(auto u : graph[node]){
            ll nwdist = distance[node][0] + u.second;
            ll oldDist = distance[u.first][0];
            if(nwdist<oldDist){
                distance[u.first][0]=nwdist;
                distance[u.first][1]=distance[node][1];
                distance[u.first][2]=distance[node][2]+1;
                distance[u.first][3]=distance[node][3]+1;
                vector<ll> tmp;
                tmp.push_back(-nwdist); tmp.push_back(u.first);
                q.push(tmp);
            }else if(nwdist==oldDist){
                distance[u.first][1]+=distance[node][1];
                distance[u.first][1] = distance[u.first][1]%mod;
                if(distance[node][2]+1<distance[u.first][2])
                    distance[u.first][2]=distance[node][2]+1;
                if(distance[node][3]+1>distance[u.first][3])
                    distance[u.first][3]=distance[node][3]+1;
            }
        }
    }

    cout << distance[n][0] << " " << distance[n][1] << " " << distance[n][2] << " " << distance[n][3];
}