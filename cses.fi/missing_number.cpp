#include <bits/stdc++.h>
auto
missing(long n) -> void;

auto
main() -> int
{
  long n;
  std::cin >> n;

  missing(n);
}
auto
missing(long n) -> void
{
  long i;
  long total = (n * (n + 1)) / 2;
  while (std::cin >> i) {
    total -= i;
  }
  std::cout << total;
}
