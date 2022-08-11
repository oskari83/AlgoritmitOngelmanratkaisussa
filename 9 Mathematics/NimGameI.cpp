#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        int n; cin >> n;
        vector<int> sticks;
        for(int j=0;j<n;j++){
            int y; cin >> y;
            sticks.push_back(y);
        }
        int val = sticks[0];
        for(int j=1;j<n;j++){
            val^=sticks[j];
        }
        if(val>0){
            cout << "first" << "\n";
        }else{
            cout << "second" << "\n";
        }
    }
}