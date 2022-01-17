#include <bits/stdc++.h>

auto
main() -> int
{
  long n;
  std::cin >> n;

  std::vector<long> num{};
  for (int tc = 0; tc < n; tc++) {
    long i;
    std::cin >> i;
    num.push_back(i);
  }

  std::sort(num.begin(), num.end());
  auto cleaned = std::unique(num.begin(), num.end());
  num.erase(cleaned, num.end());
  std::cout << num.size() << "\n";
}
