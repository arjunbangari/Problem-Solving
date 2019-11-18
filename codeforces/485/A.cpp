#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main(){ 
    fast;
    ll a,m;
    cin>>a>>m;
    for(ll i=0;i<23;i++){
        if(a%m==0){
            cout<<"Yes";
            return 0;
        }
        a += a%m;
    }
    cout<<"No";
    return 0;
}