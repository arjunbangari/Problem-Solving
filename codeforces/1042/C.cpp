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
        
    vector<ll> zeros;
    
    ll cnt = 0, ind=-1, mn=inf;
    
    for(ll i=0;i<n;i++){
        if(arr[i]==0)
            zeros.push_back(i+1);
        if(arr[i]<0){
            if(abs(arr[i])<mn)
                ind = i;
            mn = min(abs(arr[i]), mn);
            cnt++;
        }
    }
    
    ll sz = zeros.size();
    
    if(sz==n || (sz==n-1 && cnt==1)){
        for(ll i=1;i<n;i++)
            cout<<1<<" "<<i<<" "<<i+1<<endl;
        return 0;
    }
    
    if(cnt%2)
        zeros.push_back(ind+1);
    else 
        ind = -1;
    
    sz = zeros.size();
    sort(zeros.begin(), zeros.end());
    
    for(ll i=1;i<sz;i++)
        cout<<1<<" "<<zeros[i-1]<<" "<<zeros[i]<<endl;
    if(sz>0){
        cout<<2<<" "<<zeros[sz-1]<<endl;
    }
    
    ll l = 0;

    
    while(l<n-1){
        if(arr[l]==0 || l==ind){
            l++;
            continue;
        }
        
        ll r = l+1;
        while(r<n){
            if(arr[r]==0 || r==ind)
                r++;
            else
                break;
        }
        
        if(r==n)
            break;
        
        cout<<1<<" "<<l+1<<" "<<r+1<<endl;
        l = r;
    }
    
    return 0;
}