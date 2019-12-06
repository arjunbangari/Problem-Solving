#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll j;
        ll brr[n+1] = {0};
        brr[1] = 1;
        set<ll> st;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            st.insert(arr[i]);
            if(arr[i]==1)
                j = i;
        }
        ll i=j;
        st.erase(1);
        set<ll>:: iterator it;
        for(ll cur=2;cur<=n;cur++){
            if(i==0){
                j++;
                st.erase(arr[j]);
            }
            else if(j==n-1){
                i--;
                st.erase(arr[i]);
            }
            else if(arr[i-1]<arr[j+1]){
                i--;
                st.erase(arr[i]);
            } else {
                j++;
                st.erase(arr[j]);
            }
            it = st.begin();
            if(*it>cur)
                brr[cur] = 1;
            //cout<<*it<<" ";
        }
        brr[n] = 1;
        for(ll i=1;i<=n;i++)
            cout<<brr[i];
        cout<<"\n";
    }
    
    return 0;
}