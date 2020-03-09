#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<< ( n%m ? "NO" : "YES")<<endl;
    }
    
    return 0;
}