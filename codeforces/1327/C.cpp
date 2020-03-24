#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    ll arr[k][4];
    for(ll i=0;i<k;i++)
        cin>>arr[i][0]>>arr[i][1];
    for(ll i=0;i<k;i++)
        cin>>arr[i][2]>>arr[i][3];
    
    string ans;
    
    if(n==1){
        for(ll i=0;i<m;i++)
            ans += 'L';
        for(ll i=m;i<2*m;i++)
            ans += 'R';
    } 
    else if(m==1){
        for(ll i=0;i<n;i++)
            ans += 'U';
        for(ll i=0;i<n;i++)
            ans += 'D';
    }
    else{
        for(ll i=0;i<m-1;i++)
            ans += 'L';
        for(ll i=0;i<n-1;i++)
            ans += 'U';
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m-1;j++){
                if(i%2==0)
                    ans+='R';
                else
                    ans += 'L';
            }
            ans += 'D';
        }
    }
    cout<<ans.length()<<endl;
    cout<<ans<<endl;
    return 0;
}