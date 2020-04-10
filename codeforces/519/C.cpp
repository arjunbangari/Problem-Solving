#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    if(n>m)
        swap(n,m);
        
    ll ans = (n + min(2*n,m))/3;
    cout<<ans<<endl;
    
    return 0;
}