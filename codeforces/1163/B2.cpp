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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    map<ll,ll> cnt;
    multiset<ll> ms;
    
    ll ans = 0, sz = 0;
    
    for(ll i=0;i<n;i++){
        if(cnt[arr[i]]){
            ms.erase(ms.lower_bound(cnt[arr[i]]));
            sz--;
        }
        cnt[arr[i]]++;
        ms.insert(cnt[arr[i]]);
        sz++;
        
        if(sz==1)
            ans = i+1;
        else if(sz==2){
            auto a = ms.begin();
            auto b = a; b++;
            if(*a==1 || *b==(*a+1))
                ans = i+1;
        }
        else{
            auto a = ms.begin();
            auto b = ms.end(); b--;
            auto c = a; c++;
            auto d = b; d--;
            if(*a==1 && *c==*b)
                ans = i+1;
            else if(*a==*d && *b==(*d+1))
                ans = i+1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}