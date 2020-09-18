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
    
    string s;
    cin>>s;
    
    ll open = 0, i = 0, flag = 0;
    ll n = s.length();
    
    ll cnt = 0, cur = 1;
    for(auto u: s)
        cnt += (u=='#');
    
    vector<ll> ans;
    
    while(i<n){
        if(s[i]=='('){
            open++;
            i++;
        } else if (s[i]==')') {
            if(open)
                open--;
            else{
                flag = 1;
                break;
            }
            i++;
        } else if (s[i]=='#') {
            if(open<=0){
                flag = 1;
                break;
            }
            
            if(cur==cnt){
                
                ll tmp = 0;
                for(ll j=i+1;j<n;j++){
                    if(s[j]=='(')
                        tmp++;
                    else
                        tmp--;
                }
                
                if(tmp>0 || abs(tmp)>=open){
                    flag = 1;
                    break;
                }
                
                ll x = open - abs(tmp);
                ans.push_back(x);
                open -= x;
            } else {
                ans.push_back(1);
                open--;
            }
            
            cur++;
            i++;
        }
    }
    
    if(open!=0)
        flag = 1;
    
    if(flag){
        cout<<-1<<endl;
    } else {
        for(auto u: ans)
            cout<<u<<endl;
    }
    
    return 0;
}