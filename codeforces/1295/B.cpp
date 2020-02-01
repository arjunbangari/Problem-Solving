#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,x,one=0,zero=0;
        cin>>n>>x;
        string arr;
        ll bal[n];
        cin>>arr;
        
        for(ll i=0;i<n;i++){
            (arr[i]=='1' ? one++ : zero++);
            bal[i] = zero-one;
        }  
    
        if(bal[n-1]==0){
            ll flag=0;
            for(ll i=0;i<n;i++)
                if(bal[i]==x)
                    flag=1;
            cout<<(flag ? -1 : 0)<<endl;
        }
        else{
            ll ans = 0;
            for(ll i=0;i<n;i++){
                if(abs(x-bal[i])%abs(bal[n-1])==0 && ((x-bal[i])/bal[n-1])>=0)
                    ans++;
            }
            if(x==0)
                ans++;
            cout<<ans<<endl;
        }
    }
    
    return 0;
}