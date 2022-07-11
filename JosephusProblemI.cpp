#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector <int> a;
    for(int i=0;i<n;i++){
        a.push_back(i+1);
    }
    int sk = 1;
    vector <int> in;
    while(a.size()>1){
        int nn = a.size();
        for(int i=0;i<nn;i++){
            if(i%2==sk){
                cout << a[i] << " ";
                if(i==(nn-1)){
                    sk=1;
                }
            }else{
                in.push_back(a[i]);
                if(i==(nn-1)){
                    sk=0;
                }
            }
        }
        a = in;
        in.clear();
    }
    cout << a[0];
}