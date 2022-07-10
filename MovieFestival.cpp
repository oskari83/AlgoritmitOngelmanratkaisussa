#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        int a1; int a2;
        cin >> a1 >> a2;
        v.push_back(make_pair(a2,a1));
    }
    sort(v.begin(),v.end());
    int s = 1;
    int e = v[0].first;
    for(int i=1;i<n;i++){
        if(v[i].first>e && v[i].second >= e){
            s+=1;
            e = v[i].first;
        }
    }
    cout << s;
}