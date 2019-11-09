#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    ll n,a,g;
    cin>>n;
    ll suma=0,sumg=0;
    string s;
    while(n--){
        cin>>a>>g;
        if((suma+a-sumg)<=500){
            suma += a;
            s += 'A';
        }
        else{
            sumg += g;
            s += 'G';
        }
    }
    if(abs(suma-sumg)>500)
        cout<<-1;
    else
        cout<<s;

    return 0;
}
