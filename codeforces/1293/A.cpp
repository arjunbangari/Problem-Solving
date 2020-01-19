#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n,s,k,temp;
        cin>>n>>s>>k;
        unordered_set<ll> mp;
        for(ll i=0;i<k;i++){
            cin>>temp;
            mp.insert(temp);
        }
        
        ll i=s,ans1=-1e10,ans2=1e10;
        while(i>0){
            if(mp.find(i)==mp.end()){
                ans1= i;
                break;
            } i--;
        }
        i = s;
        while(i<=n){
            if(mp.find(i)==mp.end()){
                ans2 = i;
                break;
            } i++;
        }
        //cout<<i<<" "<<ans1<<" "<<ans2<<endl;
        cout<<min(s-ans1,ans2-s)<<endl;
    }
    return 0;
}