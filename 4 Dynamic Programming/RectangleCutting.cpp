#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int a,b;
    cin >> a >> b;
    int t[a+1][b+1];
    for(int i=1;i<=a;i++){
        for(int j=1; j<=b;j++){
            if(i!=j){
                t[i][j]=1e9;
            }else{
                t[i][j]=0;
            }
            for(int k=1;k<i;k++){
                t[i][j] = min(t[i][j], t[i-k][j]+t[k][j]+1); 
            }
            for(int k=1;k<j;k++){
                t[i][j] = min(t[i][j], t[i][j-k]+t[i][k]+1); 
            }
        }
    }
    cout << t[a][b];
}