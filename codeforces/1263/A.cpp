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
        ll r,g,b;
        cin>>r>>g>>b;
        ll ans = min((r+g+b)/2, r + g + b - max(r,max(g,b)));
        cout<<ans<<endl;
    }
    return 0;
}