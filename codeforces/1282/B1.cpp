#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,p,k;
        cin>>n>>p>>k;
        
        ll price[n];
        for(ll i=0;i<n;i++)
            cin>>price[i];
        
        sort(price, price+n);
        
        ll ans1=0,ans2=0, coins = p;
        
        for(ll i=1;i<n-1;i+=2){
            if(price[i+1]<=coins){
                ans1+=2;
                coins -= price[i+1];
            } else 
                break;
        }
        if(price[0]<=coins)
            ans1++;
        
        coins = p;
        
        for(ll i=0;i<n-1;i+=2){
            if(price[i+1]<=coins){
                ans2 += 2;
                coins -= price[i+1];
            } else {
                if(price[i]<=coins)
                    ans2++;
                break;
            }
        }
        
        cout<<max(ans1, ans2)<<endl;
        
    }
    
    return 0;
}