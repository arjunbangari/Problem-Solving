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
        ll n;
        cin>>n;
        
        ll sum = (n*(n+1))/2;
        
        if(sum%2)
            cout<<"NO"<<endl;
        else{
            
            vector<ll> ans;
            ll esum = 0, osum = 0;
            ll temp = 2;
            
            for(ll i=0;i<n/2;i++){
                ans.push_back(temp);
                esum += temp;
                temp += 2;
            }
            
            temp = 1;
            
            for(ll i=0;i<n/2;i++){
                ans.push_back(temp);
                osum += temp;
                temp += 2;
            }
            
            osum -= ans[n-1];
            ans[n-1] = esum - osum;
            
            cout<<"YES"<<endl;
            for(ll i=0;i<n;i++)
                cout<<ans[i]<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}