#include <iostream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int a;
    cin >> a;
    ll b[a];
    for(int i=0;i<a;i++){
        cin >> b[i];
    }
    ll ans[a];
    stack < pair <int,int> > s;
    for(int i=0;i<a;i++){
        while(s.empty()!=true && s.top().first>=b[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=0;
        }else{
            ans[i]=s.top().second;
        }
        s.push(make_pair(b[i],i+1));
    }

    for(int i=0;i<a;i++){
        cout << ans[i] << " ";
    }
}