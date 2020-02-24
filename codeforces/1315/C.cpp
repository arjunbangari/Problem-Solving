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
        ll brr[n+1],arr[2*n + 1];
        ll used[2*n +1] = {0};
        for(ll i=1;i<=n;i++){
            cin>>brr[i];
            arr[2*i - 1] = brr[i];
            used[brr[i]] = 1;
        }
        
        vector<ll> unused;
        
        for(ll i=1;i<=2*n;i++){
            if(!used[i])
                unused.push_back(i);
        }
        
        ll flag = 0;
        for(ll i=2;i<=2*n;i+=2){
            ll pos=-1;
            for(ll j=0;j<unused.size();j++){
                if(unused[j]>arr[i-1]){
                    pos = j;
                    break;
                }
            }
            if(pos==-1){
                flag = 1;
                break;
            } else {
                arr[i] = unused[pos];
                unused[pos] = -1000;
            }
        }
        
        if(flag)
            cout<<-1<<endl;
        else{
            for(ll i=1;i<=2*n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}