#include<cstdio>
int Case,n,i,k,sum,a[50010];
bool check(int L,int R){
  int l=L,r=R,i,cnt=0;
  while(l<r&&a[l]==a[r])l++,r--;
  for(i=l;i<=r;i+=2)if(a[i]^a[i+1])return 0;
  for(i=L;i<=R;i++)cnt+=a[i];
  return cnt/2%2==0;
}
int solve(){
  scanf("%d",&n);
  sum=0;
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);
    sum^=a[i];
  }
  if(!sum)return 0;
  if(n%2==0)return 1;
  for(k=30;!(sum>>k&1);k--);
  for(i=1;i<=n;i++)a[i]=a[i]>>k&1;
  if(!a[1]&&!a[n])return -1;
  if(a[1]&&check(2,n))return 1;
  if(a[n]&&check(1,n-1))return 1;
  return -1;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    int t=solve();
    if(t==1)puts("First");
    if(t==0)puts("Draw");
    if(t==-1)puts("Second");
  }
}
