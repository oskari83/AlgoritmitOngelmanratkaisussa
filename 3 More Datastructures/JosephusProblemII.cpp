#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    indexed_set s;
    for (int i = 0; i<n; i++){
        s.insert(i+1);
    }
    int d = k;
    while (s.size()>0){
        d= d%s.size();
        auto t = s.find_by_order(d);
        s.erase(t);
        cout << *t << " ";
        d+=k;
    }
}