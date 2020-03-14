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
        ll n,val;
        cin>>n;
        set<ll> s;
        for(ll i=0;i<n;i++){
            cin>>val;
            s.insert(val);
        }
        ll sz = s.size();
        cout<<sz<<endl;
    }
    return 0;
}