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
        vector<int> balls;
        for(int j=0;j<n;j++){
            int y; cin >> y;
            balls.push_back(y);
        }

        int val = balls[1];
        for(int j=1;j<(n/2);j++){
            val^=balls[j*2+1];
        }

        if(val>0){
            cout << "first" << "\n";
        }else{
            cout << "second" << "\n";
        }
    }
}