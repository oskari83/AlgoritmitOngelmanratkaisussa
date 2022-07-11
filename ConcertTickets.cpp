#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    cin >> n >> m;
    multiset <int> tickets;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        tickets.insert(-x); 
    }
    for(int i=0;i<m;i++){
        int y;
        cin >> y;
        auto it = tickets.lower_bound(-y);
        int val = *it;
        if(it!=tickets.end()){
            cout << -val << "\n";
            tickets.erase(tickets.find(val));
        }else{
            cout << -1 << "\n";
        }
    }
}