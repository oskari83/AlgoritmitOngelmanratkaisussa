#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int visited[100005];
deque<ll> graph[100005];

void dfs(ll s) {
    if (visited[s]==1) 
        return;
    visited[s] = 1;
    for (auto u: graph[s]) {
        dfs(u);     
    }
}

int main() {
    ll n,m;
    cin >> n >> m;
    set<ll> target;
    for(int i=0; i<m; i++){
        ll a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        target.insert(a);
        target.insert(b);
    }

    //making sure an eulerian circuit exists from node 1
    for(int i=0;i<100005;i++){
        visited[i]=0;
    }
    dfs(1);
    ll sumtot =0;
    for(int i=0;i<100005;i++){
        if(visited[i]==1)
            sumtot+=1;   
    }
    ll n2=target.size();
    if(sumtot!=n2){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<n+1;i++){
        if(graph[i].size()%2!=0){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    //now that we are sure it exists we find it using Hierholzer's algorithm
    stack<ll> st;
    vector<ll> circuit;
    st.push(1);
    while(!st.empty()){
        ll currentNode=st.top();
        if(!graph[currentNode].empty()){
            ll nextNode=graph[currentNode][0];
            st.push(nextNode);
            graph[currentNode].pop_front();
            int i=0;
            while(graph[nextNode][i]!=currentNode){
                i++;
            }
            graph[nextNode].erase(graph[nextNode].begin()+i);
        }else{
            circuit.push_back(currentNode);
            st.pop();
        }
    }
    for(int i=circuit.size()-1;i>=0;i--){
        cout << circuit[i] << " ";
    }
}