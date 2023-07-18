
/**    Tuhin ahmed                    **
*      Email:tuhin107494@gmail.com     *
*      university:comilla university  **
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree< pair<int,pair<int,int> > ,null_type,less< pair<int,pair<int,int> > >,rb_tree_tag,
        tree_order_statistics_node_update>ordered_set;
#define TT ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define       ll                   long long int
#define       ull                  unsigned long long int
#define       vi                   vector<int>
#define       vc                   vector<char>
#define       vs                   vector<string>
#define       vll                  vector<long long int>
#define       vp                   vector<  pair<int,int> >
#define       pb                   push_back
#define       pob                  pop_back
#define       pll                  pair<long long  int, long long int>
#define       F                    first
#define       S                    second
#define       sc(x)                scanf("%lld",&x)
#define       sci(x)                scanf("%d",&x)
#define       sc2(x,y)             scanf("%lld %lld",&x,&y)
#define       pf                   printf
#define       min3(a,b,c)          min(a,b<c?b:c)
#define       max3(a,b,c)          max(a,b>c?b:c)
#define       all(v)               v.begin(), v.end()
#define       rall(v)               v.rbegin(), v.rend()
#define       nl                   '\n'
#define       yes                  "YES\n"
#define       no                   "NO\n"
///============ CONSTANT ===============///
#define mx18  1000000000000000000
#define mx9   1000000007
#define mx8   100000007
#define mx7   10000006
#define mx6   1000056
#define mx5   200005
#define mx4   10005
#define inf   1<<30
#define eps   1e-9
#define mod   mx9
#define mod2   1000000009
ll dx[]= {1,0,-1,0};
ll dy[]= {0,1,0,-1};
long double PI = acosl(-1);
///=============== Debugging ============================///
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
ll cs=0;
pair<ll,pair<ll,ll> >tr[2][mx6];
pair<ll,ll> pw[mx6];
vector<string>v;
void pre()
{

  pw[0]={1,1};
  ll b=347;
  for(int i=1;i<mx5;i++)
  {
     ll l=(b*pw[i-1].F)%mod;
     ll r=(b*pw[i-1].S)%mod2;
     pw[i]={l,r};
  }

}
void build(int u,int b,int e,int id)
{
      if(b==e)
      {  
         tr[id][u]={(ll)v[id][b],{(ll)v[id][b],1}};;
         return;
      }
      ll mid=(b+e)/2;
      build(2*u,b,mid,id);
      build(2*u+1,mid+1,e,id);

     ll l_sz=mid-b+1;
     ll r_sz=e-(mid+1)+1;
     ll sz=l_sz+r_sz;
     

    ll l=(((tr[id][2*u].F*pw[r_sz].F)%mod)+tr[id][2*u+1].F)%mod;
    ll r=(((tr[id][2*u].S.F*pw[r_sz].S)%mod2)+tr[id][2*u+1].S.F)%mod2;

    tr[id][u]={l,{r,sz}};


}
pair<ll,pair<ll,ll> > quary(int u,int b,int e,int i,int j,int id)
{
      if(e<i or b>j)return {0,{0,0}};
      else if(b>=i and e<=j)
      {
         return tr[id][u];
      }
      int   mid=(b+e)/2;

     pair<ll,pair<ll,ll> > left=quary(2*u,b,mid,i,j,id);
     pair<ll,pair<ll,ll> > right=quary((2*u)+1,mid+1,e,i,j,id);

     ll l_sz=left.S.S;
     ll r_sz=right.S.S;
     ll sz=l_sz+r_sz;

    ll l=(((left.F*pw[r_sz].F)%mod) +right.F)%mod;
    ll r=(((left.S.F*pw[r_sz].S)%mod2)+right.S.F)%mod2;
    
    
    return  {l,{r,sz}};
}
void  update (int u,int b,int e,int i,int j,int x,int id )
{
   if(e<i or b>j)return;
   else if(b>=i and e<=j)
      {
         debug(u,x);
         if(x==0)tr[id][u]={x,{x,0}};
         else tr[id][u]={x,{x,1}};
         return;
      }
      int mid=(b+e)/2;

      update(2*u,b,mid,i,j,x,id);
      update((2*u)+1,mid+1,e,i,j,x,id);

     ll l_sz=tr[id][2*u   ].S.S;
     ll r_sz=tr[id][2*u +1].S.S;
     ll sz=l_sz+r_sz;

    ll l=(((tr[id][2*u].F*pw[r_sz].F)%mod)+tr[id][2*u+1].F)%mod;
    ll r=(((tr[id][2*u].S.F*pw[r_sz].S)%mod2)+tr[id][2*u+1].S.F)%mod2;

    tr[id][u]={l,{r,sz}};
}

ll bs(ll x,ll n,ll id)
{

      ll l,r,f=0;
     l=0,r=n-1;

     while(l<=r)
     {
      if(l==r){f++;if(f==2)break;}
      ll mid=(l+r)/2;
      if(quary(1,0,n-1,0,mid,id).S.S>=x)
      {
         r=mid;
      }
      else l=mid+1;
     }
     return r;
}

void input()
{
  ll m,n,sizee=0,ans=0;
 string a;
 cin>>a;
 n=a.size();

 v.pb(a);
 reverse(all(a));
 v.pb(a);

 build(1,0,n-1,0);
 build(1,0,n-1,1);

 cin>>m;
 while(m--)
 {
   char c;
   cin>>c;
   if(c=='C')
   {
      ll l,r;
      cin>>l>>r;

      ll l1=bs(l,n,0);
      ll r1=bs(r,n,0);
      ll rf=n-l1-1;
      ll lf=n-r1-1;

      //debug(l1,r1,lf,rf);

      if(quary(1,0,n-1,l1,r1,0)==quary(1,0,n-1,lf,rf,1))
      {
         cout<<"Yes!"<<endl;
      }
      else cout<<"No!"<<endl;

      //cout<<quary(1,0,n-1,l1,r1,0).F<<" "<<quary(1,0,n-1,l1,r1,0).S.F<<endl;
      //cout<<quary(1,0,n-1,lf,rf,1).F<<" "<<quary(1,0,n-1,lf,rf,1).S.F<<endl;
   }
   else if(c=='D')
   {
      ll l,r,f=0,x;
       cin>>x;
       x=bs(x,n,0);
       update(1,0,n-1,x,x,0,0);
       update(1,0,n-1,n-x-1,n-x-1,0,1);
   }
   else
   {
      ll l,x;
      char ch;
      cin>>l>>ch;
      x=bs(l,n,0);

       update(1,0,n-1,x,x,ch,0);
       update(1,0,n-1,n-x-1,n-x-1,ch,1);
   }
 }

}
void ifdef()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
}
int main()
{
   TT;
   ifdef();
   pre();
   int t=1;
    //cin>>t;
    while(t--)
    {

        input();

    }
    return 0;
}


