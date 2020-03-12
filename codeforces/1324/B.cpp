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
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        ll flag = 0;
        for(ll i=0;i<n;i++){
            for(ll j=i+2;j<n;j++){
                if(arr[i]==arr[j]){
                    flag = 1;
                    break;
                }
            }
        }
        
        cout<< (flag ? "YES" : "NO")<<endl;
        
    }
    return 0;
}