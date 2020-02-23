#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    ll s[n];
    for(ll i=0;i<n;i++)
        cin>>s[i];
    
    ll l=0,r=0,ans = 0,curr=k,left=0,right=0;
    while(l<n && r<n){
        if(s[r]==1)
            r++;
        else{
            if(curr==0){
                if(s[l]==0){
                    curr++;
                }
                l++;
            } else {
                r++;
                curr--;
            }
        }
        if((r-l)>ans){
            ans = r-l;
            left = l;
            right = r;
        }
    }
    cout<<ans<<endl;
    for(ll i=left;i<right;i++)
        s[i] = 1;
    for(ll i=0;i<n;i++)
        cout<<s[i]<<" ";
    
    return 0;
}