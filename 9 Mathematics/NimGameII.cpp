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
        vector<int> grunNums;

        for(auto v : sticks){
            int vl = v%4;
            grunNums.push_back(vl);
        }

        int val = grunNums[0];
        for(int j=1;j<n;j++){
            val^=grunNums[j];
        }
        if(val>0){
            cout << "first" << "\n";
        }else{
            cout << "second" << "\n";
        }
    }
}