#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        vector<ll> v({a,b,a^b});
        cout<<v[n%3]<<endl;
    }
    
    return 0;
}