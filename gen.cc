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

// This is xoroshiro128+ 1.0
// Reference : http://prng.di.unimi.it/xoroshiro128plus.c
class Xoroshiro {
 public:
  Xoroshiro() {
    s[0] = static_cast<uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
    s[1] = s[0] ^ 0xffffffffful;
    for (int i = 0; i < (1 << 6); ++i) next();
  }

  using result_type = uint64_t;
  static constexpr uint64_t min() { return std::numeric_limits<result_type>::min(); }
  static constexpr uint64_t max() { return std::numeric_limits<result_type>::max(); }

  uint64_t operator()() { return next(); }

 private:
  uint64_t s[2];

  static inline uint64_t rotl(const uint64_t x, int k) {
    return (x << k) | (x >> (64 - k));
  }

  uint64_t next() {
    const uint64_t s0 = s[0];
    uint64_t s1 = s[1];
    const uint64_t result = s0 + s1;
    s1 ^= s0;
    s[0] = rotl(s0, 24) ^ s1 ^ (s1 << 16);
    s[1] = rotl(s1, 37);

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  constexpr int n = 1000;
  constexpr int q = 1000;
  constexpr int max_val = (int)1e5;
  cout << n << " " << q << '\n';
  Xoroshiro rng;
  uniform_int_distribution<int> range_modify(0, max_val);
  uniform_int_distribution<int> range_get(0, n - 1);
  uniform_int_distribution<int> type_query(0, 1);

  for (int i = 0; i < n; ++i) {
    int op = type_query(rng);
    cout << op << " ";
    int l = -1, r = -1;
    while (l >= r) {
      l = range_get(rng), r = range_get(rng);
    }
    cout << l << " " << r;
    if (op == 0) {
      cout << " " << range_modify(rng) << '\n';
    } else {
      cout << '\n';
    }
  }

  return 0;
}
