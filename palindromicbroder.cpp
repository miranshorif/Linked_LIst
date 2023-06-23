#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b); --i >= (a); )

int ri()
{
  int x;
  cin>>x;
  return x;
}

const int N = 1e6;
char a[N+1];
struct Node { int suff, l, c[26], cnt; } b[N+2];

int getSuff(int i, int x)
{
  while (i-1-b[x].l < 0 || a[i-1-b[x].l] != a[i])
    x = b[x].suff;
  return x;
}

int main()
{
  b[0].suff = 1; b[0].l = 0;
  b[1].suff = 1; b[1].l = -1;
  cin>>a;
  int x = 1, y = 2;
  for (int i = 0; a[i]; i++) {
    x = getSuff(i, x);
    if (! b[x].c[a[i]-'a']) {
      b[y].l = b[x].l+2;
      b[y].suff = b[getSuff(i, b[x].suff)].c[a[i]-'a'];
      b[y].cnt = 0;
      b[x].c[a[i]-'a'] = y++;
    }
    x = b[x].c[a[i]-'a'];
    b[x].cnt++;
  }
  ROF(i, 0, y)
    b[b[i].suff].cnt += b[i].cnt;
  ll ans = 0;
  FOR(i, 2, y) {
    int c = b[i].cnt;
    ans += ll(c-1)*c/2;
  }
  ans=ans%1000000007;
  cout<<ans<<endl;
}
