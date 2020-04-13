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
        ll max_element=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            max_element = max(max_element, arr[i]);
        }
        
        vector<ll> v[max_element+1];
        ll siz[max_element+1] = {0};
        for(ll i=0;i<n;i++){
            v[arr[i]].push_back(i);
            siz[arr[i]]++;
        }
        
        ll mx = 0;
        
        for(ll i=1;i<=max_element;i++){
            for(ll j=1;j<=max_element;j++){
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
        for(ll i=1;i<=max_element;i++)
            mx = max(mx, siz[i]);
        
        cout<<mx<<endl;
        
    }
    
    return 0;
}