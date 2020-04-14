#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll arr[n];
        ll cnt[201] = {0};
        vector<ll> v[201];
        ll siz[201] = {0};
 
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        for(ll i=0;i<n;i++){
            v[arr[i]].push_back(i);
            siz[arr[i]]++;
            cnt[arr[i]] = 1;
        }
        
        vector<ll> req_array;
        for(ll i=1;i<201;i++)
            if(cnt[i])
                req_array.push_back(i);
        
        ll mx = 0;
        
        for(ll i : req_array){
            mx = max(mx, siz[i]);
            for(ll j : req_array ){
                if(j==i)
                    continue;
                ll sz = siz[i];
                for(ll k=0;k<(sz/2);k++){
                    auto temp1 = lower_bound(v[j].begin(), v[j].end(), v[i][k]);
                    auto temp2 = lower_bound(v[j].begin(), v[j].end(), v[i][sz-k-1]);
                    ll len = temp2-temp1;
                    mx = max(mx, len + 2*(k+1));
                }
            }
        }
        
        cout<<mx<<endl;
        
    }
    
    return 0;
}