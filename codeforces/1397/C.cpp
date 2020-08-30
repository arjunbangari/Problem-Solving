#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    if(n==1){
        cout<<1<<" "<<1<<endl;
        cout<<n-arr[0]<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<-n<<endl;
        cout<<1<<" "<<1<<endl;
        cout<<0<<endl;
        return 0;
    }    
        
    vector<ll> brr(n);
    for(ll i=0;i<n;i++)
        brr[i] = (arr[i]+n)%n;
    
    cout<<1<<" "<<n-1<<endl;
    
    for(ll i=0;i<n-1;i++){
        cout<<(n-1)*brr[i]<<" ";
        arr[i] += (n-1)*brr[i];
    }
    cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<n - arr[n-1]<<endl;
    arr[n-1] = n;
    
    cout<<1<<" "<<n<<endl;
    for(ll i=0;i<n;i++)
        cout<<-arr[i]<<" ";
    cout<<endl;
    
    return 0;
}