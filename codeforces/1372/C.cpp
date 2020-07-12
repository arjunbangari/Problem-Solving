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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
            
        ll i = 0;
        while(i<n && arr[i]==(i+1))
            i++;
            
        ll j = n-1;
        while(j>=0 && arr[j]==(j+1))
            j--;
        
        ll cnt = 0, x = (j-i+1);
        for(ll k=i;k<=j;k++)
            if(arr[k]==(k+1))
                cnt++;
            
        if(i>j)
            cnt = x;
        
        if(cnt==0){
            cout<<1<<endl;
        } else if(cnt==x){
            cout<<0<<endl;
        } else {
            cout<<2<<endl;
        }
    }
    
    return 0;
}