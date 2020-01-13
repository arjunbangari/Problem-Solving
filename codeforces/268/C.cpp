#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    ll k = min(n,m)+1;
    cout<<k<<endl;
    for(ll i=0;i<k;i++){
        cout<<i<<" "<<k-i-1<<endl;
    }
    
    return 0;
}