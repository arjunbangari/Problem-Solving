#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    string s;
    cin>>s;
    
    ll n = s.length(), curmax = -1;
    map<ll, ll> mp;
    stack<ll> st;
    
    vector<ll> arr(n);
    arr[0] = -1;
    
    for(ll i=0;i<n;i++){
        if(s[i]=='('){
            st.push(i);
            arr[i] = -1;
        }
        else{
            if(st.empty())
                arr[i] = -1;
            else{
                ll val = st.top();
                st.pop();
                arr[i] = val;
                while((arr[i]-1)>=0 && (arr[arr[i]-1])!=-1)
                    arr[i] = arr[arr[i]-1];
                mp[i - arr[i]+1]++;
                curmax = max(curmax, i-arr[i]+1);
            }
        }
    }
    
    if(curmax==-1){
        cout<<"0 1"<<endl;
        return 0;
    }
    
    cout<<curmax<<" "<<mp[curmax]<<endl;
    
    return 0;
}