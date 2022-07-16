#include <iostream>
#include <set>
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
    sort(b, b+a);
    ll mid;
    if(a%2==0){
        mid=a/2;
    }else{
        mid=(a-1)/2;
    }
    ll med=b[mid];
    ll s=0;
    for(int i=0;i<a;i++){
        if(med>b[i]){
            s+=(med-b[i]);
        }else{
            s+=(b[i]-med);
        }
    }

    cout << s;
}