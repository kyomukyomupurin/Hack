#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using int64 = long long;

#define all(_) begin(_), end(_)
#define rall(_) rbegin(_), rend(_)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  constexpr int inf = 2147483647;
  vector<int> v(n, inf);

  while (q--) {
    int op; cin >> op;
    if (op == 0) {
      int s, t, x; cin >> s >> t >> x;
      for (int i = s; i <= t; ++i) v[i] = x;
    } else {
      int s, t; cin >> s >> t;
      int mn = inf;
      for (int i = s; i <= t; ++i) mn = min(mn, v[i]);
      cout << mn << '\n';
    }
  }

  return 0;
}
