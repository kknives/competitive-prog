#include <bits/stdc++.h>

auto
main() -> int
{
  int cases;
  std::cin >> cases;

  std::vector<unsigned int> a_seq;
  for (auto i = cases; i > 0; i--) {
    unsigned int k;
    std::cin >> k;
    if (k % 2 != 0) {
      std::cout << 0 << "\n";
      continue;
    }
    a_seq.emplace_back(k / 2);
    unsigned int sum = k / 2;
    while ((k - sum) % 2 == 0) {
      unsigned int el = (k - sum) / 2;
      a_seq.emplace_back(el);
      sum += el;
    }
    std::cout << a_seq.size() << "\n";
    a_seq.clear();
  }
}
