#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> graph[200005];
int toLeaf[200005];
int max2[200005];
int childofmax[200005];

void dfs(int s, int prev) {
    toLeaf[s]=0;
    max2[s]=0;
    for(auto u: graph[s]) {
        if(u!=prev){
            dfs(u,s); 
            if(toLeaf[u]+1>toLeaf[s]){
                max2[s]=toLeaf[s];
                toLeaf[s]=toLeaf[u]+1;
                childofmax[s]=u;
            }else if(toLeaf[u]+1>max2[s]){
                max2[s]=toLeaf[u]+1;
            }
        }
    }
}

void dfs2(int s, int prev) {
    for(auto u: graph[s]) {
        if(u!=prev){
            if(u==childofmax[s]){
                if(max2[s]+1>toLeaf[u]){
                    max2[u]=toLeaf[u];
                    toLeaf[u]=max2[s]+1;
                    childofmax[u]=s;
                }else if(max2[s]+1>max2[u]){
                    max2[u]=max2[s]+1;
                }   
            }else{
                max2[u]=toLeaf[u];
                toLeaf[u]=toLeaf[s]+1;
                childofmax[u]=s;
            }
            dfs2(u,s);
        }
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
    dfs(1,0);
    dfs2(1,0);
    for(int i=1;i<n+1;i++){
        cout << toLeaf[i] << " ";
    }    
}