#include <bits/stdc++.h>

auto
numat(long y, long x) -> long
{
  long ans = -1;
  if (x >= y) {
    long sq = x * x;
    if (x % 2 == 0)
      ans = (x - 1) * (x - 1) + (y - 1) + 1;
    else
      ans = sq - (y - 1);
  } else {
    long sq = y * y;
    if (y % 2 == 0)
      ans = sq - (x - 1);
    else
      ans = (y - 1) * (y - 1) + 1 + (x - 1);
  }
  return ans;
}
auto
main() -> int
{
  int tc;
  std::cin >> tc;
  while (tc--) {
    long x, y;
    std::cin >> y >> x;
    std::cout << numat(y, x) << "\n";
  }
}
