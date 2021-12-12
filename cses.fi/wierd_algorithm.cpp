#include <bits/stdc++.h>

auto
w_algo(long n) -> void;
auto
main() -> int
{
  long n;
  std::cin >> n;

  w_algo(n);
}
auto
w_algo(long n) -> void
{
  long value = n;
  // std::vector<int> steps{value};
  std::cout << value << " ";
  while (value != 1) {
    if (value % 2 == 0) {
      value /= 2;
    } else {
      value = value * 3 + 1;
    }
    // steps.push_back(value);
    std::cout << value << " ";
  }
}
