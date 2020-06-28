#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
        ll n,k;
        cin>>n>>k;
        
        vector<ll> both, alice, bob;
        
        for(ll i=0;i<n;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            
            if(b && c)
                both.push_back(a);
            else if(b)
                alice.push_back(a);
            else if(c)
                bob.push_back(a);
        }
        
        ll sz1 = alice.size(), sz2 = bob.size(), sz3 = both.size();
        
        if((sz1+sz3)<k || (sz2+sz3)<k){
            cout<<-1<<endl;
            return 0;
        }
        
        ll ans = inf;
        
        sort(both.begin(), both.end());
        sort(alice.begin(), alice.end());
        sort(bob.begin(), bob.end());
        
        for(ll i=1;i<max({sz1, sz2, sz3}) ;i++){
            if(i<sz1)
                alice[i] += alice[i-1];
            if(i<sz2)
                bob[i] += bob[i-1];
            if(i<sz3)
                both[i] += both[i-1];
        }
        
        for(ll i=0;i<sz3 && i<k;i++){
            if(sz2<(k-i-1) || sz1<(k-i-1))
                continue;
            ll val = both[i];
            if(i!=(k-1))
                val += alice[k-i-2] + bob[k-i-2];
            ans = min(ans, val);
        }
        
        if(sz1>=k && sz2>=k)
            ans = min(ans, alice[k-1] + bob[k-1]);
        
        cout<<ans<<endl;
    
    return 0;
}