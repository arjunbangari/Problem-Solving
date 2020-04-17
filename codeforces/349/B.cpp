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
    
    ll v;
    cin>>v;
    
    ll arr[10];
    for(ll i=1;i<=9;i++)
        cin>>arr[i];
    
    ll mn = 1e9, ind;
    for(ll i=9;i>0;i--){
        if(arr[i]<mn)
            ind = i;
        mn = min(mn, arr[i]);
    }
    
    ll len = v/mn;
    
    vector<ll> ans;
    for(ll i=0;i<len;i++)
        ans.push_back(ind);
        
    ll rem = v%mn;
    
    for(ll i=0;i<len;i++){
        ll temp = rem + arr[ind];
        ll val = 0;
        for(ll j=9;j>0;j--){
            if(arr[j]<=temp){
                val = j;
                break;
            }
        }
        
        if(val){
            rem = temp - arr[val];
            ans[i] = val;
        } else {
            break;
        }
        
    }
    
    if(ans.empty())
        cout<<-1<<endl;
    else{
        for(ll i=0;i<len;i++)
            cout<<ans[i];
    }
    
    return 0;
}