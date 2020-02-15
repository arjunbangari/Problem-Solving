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
        ll n,sum=0,l=0;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll mx=0,mn = 1e9,ans=0;
        
        for(ll i=0;i<n;i++){
            if(arr[i]!=-1){
                if((i>0 && arr[i-1]==-1) || (i<(n-1) && arr[i+1]==-1)){
                    mx = max(mx,arr[i]);
                    mn = min(mn,arr[i]);
                    ans++;
                }
            }
        }
        if(ans>0){
        ll k = round((double)(mn+mx)/(double)2);
        
        for(ll i=0;i<n;i++)
            if(arr[i]==-1)
                arr[i] = k;
        
        ll m = -1;
        ll t1,t2;
        for(ll i=0;i<n-1;i++){
            t1 = (arr[i]==-1 ? k : arr[i]);
            t2 = (arr[i+1]==-1 ? k : arr[i+1]);
            m = max(m,abs(t1-t2));
        }
        cout<<m<<" "<<k<<endl;
        }
        else 
            cout<<0<<" "<<0<<endl;
    }
    return 0;
}