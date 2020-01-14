#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,sum=0,res=0,mx=-1;
    vector<ll> ans;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        mx=max(mx,arr[i]);
    }
        
    sum-=mx;
    for(ll i=0;i<n;i++){
        if(arr[i]!=mx && (sum-arr[i])==mx){
            res++;
            ans.push_back(i+1);
        }
    }
    
    vector<ll> ind;
    for(ll i=0;i<n;i++){
        if(arr[i]==mx)
            ind.push_back(i+1);
    }
    
    sort(arr,arr+n);
    if(arr[n-1]!=arr[n-2]){
        if((sum-arr[n-2])==arr[n-2]){
            res++;
            ans.push_back(ind[0]);
        }
    } else {
        if((sum-mx)==mx){
            res+=ind.size();
            for(auto i: ind)
                ans.push_back(i);
        }
    }
    
    cout<<res<<endl;
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}