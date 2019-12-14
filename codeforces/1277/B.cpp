#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,temp;
        cin>>n;
        set<ll,greater<ll>> s;
        unordered_set<ll> us;
        for(ll i=0;i<n;i++){
            cin>>temp;
            if(temp%2==0)
                s.insert(temp);
        }
        for(auto i: s)
            us.insert(i);
        ll ans=0;
        for(auto i: s){
            while(true){
                i = i/2;
                ans++;
                if(us.find(i)!=us.end() || i%2!=0)
                    break;
                else
                    continue;
            }
        }
        cout<<ans<<"\n";
    
        
        
    }
    return 0;
}
