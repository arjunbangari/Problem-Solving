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
        ll n,k, temp;
        cin>>n;
        vector<ll> arr[n];
        
        for(ll i=0;i<n;i++){
            cin>>k;
            for(ll j=0;j<k;j++){
                cin>>temp;
                temp--;
                arr[i].push_back(temp);
            }
        }
        
        ll vis[n] = {0};
        ll yes[n] = {0};
        ll ind=-1, flag=0;
        
        for(ll i=0;i<n;i++){
            for(ll u: arr[i]){
                if(!vis[u]){
                    vis[u] = 1;
                    yes[i] = 1;
                    break;
                }
            }
            if(!yes[i] && !flag){
                ind = i;
                flag = 1;
            }
        }
        
        if(ind==-1)
            cout<<"OPTIMAL"<<endl;
        else {
            cout<<"IMPROVE"<<endl;
            cout<<ind+1<<" ";
            for(ll i=0;i<n;i++){
                if(!vis[i]){
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
        
    }
    
    return 0;
}