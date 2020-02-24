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
        ll a,b,x,y;
        cin>>a>>b>>x>>y;
        ll t1 = max(x,a-x-1);
        ll t2 = max(y,b-y-1);
        ll ans = max(t1*b,t2*a);
        cout<<ans<<endl;
    }
    return 0;
}