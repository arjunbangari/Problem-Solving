#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    fast;
    ll n,m,d;
    cin>>n>>m>>d;
    ll arr[n*m];
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i*m + j];
    
    sort(arr,arr+(n*m));
    ll mid=arr[(n*m)/2];
    //cout<<mid<<"\n";
    ll ans=0;
    bool flag=true;
    for(ll i=0;i<n*m;i++){
        ll temp=abs(mid-arr[i]);
        if(temp%d!=0){
            flag = false;
            break;
        }
        else{
            //cout<<temp<<" ";
            ans+= temp/d;
        }
    }
    if(flag)
        cout<<ans<<"\n";
    else
        cout<<-1<<"\n";
    return 0;
}
