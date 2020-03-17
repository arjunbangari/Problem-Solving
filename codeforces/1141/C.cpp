#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    
    ll qrr[n-1];
    for(ll i=0;i<n-1;i++)
        cin>>qrr[i];
    
    ll sum=qrr[0], last = qrr[0];
    for(ll i=1;i<n-1;i++){
        last += qrr[i];
        sum += last;
    }
    
    ll p0 = ((n*(n+1))/2 - sum)/n;
    
    ll arr[n];
    arr[0] = p0;
    
    for(ll i=1;i<n;i++)
        arr[i] = arr[i-1] + qrr[i-1];
    
    ll brr[n];
    for(ll i=0;i<n;i++)
        brr[i] = arr[i];
    
    sort(arr,arr+n);

    for(ll i=0;i<n;i++){
        if(arr[i]!=(i+1)){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    for(ll i=0;i<n;i++)
        cout<<brr[i]<<" ";
    
    return 0;
}