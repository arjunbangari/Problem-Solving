#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    fast;
    ll n;
    cin>>n;
    vector<ll> arr;
    for(ll i=1;i<100001;i++){
        ll temp = (i*(i+1))/2;
        arr.push_back(temp);
    }
    bool flag=false;
    ll i=0,j=99999;
    while(i<=j){
        if((arr[i]+arr[j])>n)
            j--;
        else if((arr[i]+arr[j])<n)
            i++;
        else{
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
    return 0;
}
