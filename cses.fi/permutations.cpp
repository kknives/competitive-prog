#include <bits/stdc++.h>

auto
beau_seq(long n) -> void;
auto
main() -> int
{
  long n;
  std::cin >> n;
  beau_seq(n);
}
auto
beau_seq(long n) -> void
{
  std::deque<long> seq = { 2, 4, 1, 3 };
  if (n == 1) {
    std::cout << "1"
              << "\n";
  } else if (n < 4) {
    std::cout << "NO SOLUTION"
              << "\n";
  } else {
    for (int x = n - 4; x > 0; x--) {
      if (x % 2 == 0) {
        seq.push_front(x + 4);
      } else {
        seq.push_back(x + 4);
      }
    }
    for (auto x : seq) {
      std::cout << x << " ";
    }
  }
}
