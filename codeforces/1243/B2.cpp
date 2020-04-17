#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// actual code

int main(){
    fast;
    
    ll k;
    cin>>k;
    
    while(k--){
        ll n;
        cin>>n;
        
        string s, t;
        
        cin>>s>>t;
        
        ll cnt[30] = {0};
        
        for(ll i=0;i<n;i++){
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']++;
        }
        
        ll flag = 0;
        
        for(ll i=0;i<26;i++)
            if(cnt[i]%2)
                flag = 1;
        
        if(!flag){
            ll m=0;
            vector<pair<ll,ll>> swaps;
            
            for(ll i=0;i<n;i++){
                if(s[i]==t[i])
                    continue;
                
                ll ind = 0;
                
                for(ll j=i+1;j<n;j++)
                    if(s[j]==s[i])
                        ind = j;
                
                if(ind){
                    m++;
                    swaps.push_back({ind,i});
                    swap(t[i], s[ind]);
                } else {
                    
                    for(ll j=i+1;j<n;j++)
                        if(t[j]==s[i])
                            ind = j;
                    
                    m += 2;
                    swaps.push_back({ind,ind});
                    swaps.push_back({ind,i});
                    swap(t[ind], s[ind]);
                    swap(t[i], s[ind]);
                }
            }
            
            cout<<"Yes"<<endl<<m<<endl;
            for(auto u: swaps)
                cout<<u.first+1<<" "<<u.second+1<<endl;
            
        } else {
            cout<<"No"<<endl;
        }
            
            
    }
    
    return 0;
}