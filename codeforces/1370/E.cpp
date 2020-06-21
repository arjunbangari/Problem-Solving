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
    
    string s, t;
    cin>>s>>t;
    
    ll one = 0, zero = 0;
    
    for(ll i=0;i<n;i++){
        if(s[i]=='1')
            one++;
        if(s[i]=='0')
            zero++;
        if(t[i]=='1')
            one--;
        if(t[i]=='0')
            zero--;
    }
    
    if(one!=0 || zero!=0){
        cout<<-1<<endl;
        return 0;
    }
    
    set<ll> s01, s10;
    
    for(ll i=0;i<n;i++){
        if(s[i]=='1' && t[i]=='0')
            s10.insert(i);
        if(s[i]=='0' && t[i]=='1')
            s01.insert(i);
    }
    
    ll ans = 0;
    
    while(!s01.empty() && !s10.empty()){
        if((*s01.begin())<(*s10.begin())){
            ll x = -1;
            while(1){
                auto it = s01.lower_bound(x);
                if(it==s01.end())
                    break;
                
                x = *it;
                s01.erase(it);
                
                auto it1 = s10.lower_bound(x);
                if(it1==s10.end())
                    break;
                
                x = *it1;
                s10.erase(it1);
            }
        } else {
            ll x = -1;
            while(1){
                auto it = s10.lower_bound(x);
                if(it==s10.end())
                    break;
                
                x = *it;
                s10.erase(it);
                
                auto it1 = s01.lower_bound(x);
                if(it1==s01.end())
                    break;
                
                x = *it1;
                s01.erase(it1);
            }
        }  
        ans++;
    }
    
    ll sz1 = s01.size();
    ll sz2 = s10.size();
    
    ans += sz1 + sz2;
    
    cout<<ans<<endl;
    
    return 0;
}