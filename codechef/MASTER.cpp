#include <bits/stdc++.h>

auto
main() -> int
{
  unsigned int len, qur;
  std::cin >> len;
  std::cin >> qur;

  std::vector<unsigned int> seq(len, 0u);
  for (auto i = 0u; i < len; i++) {
    std::cin >> seq[i];
  }
  for (auto pc = qur; pc > 0u; pc--) {
    int ins;
    std::cin >> ins;
    if (ins == 1) {
      // Pass
    } else {
      unsigned int k;
      std::cin >> k;
      unsigned int sum = 0;
      for (auto a = 0u; a < k; a++) {
        auto prev = sum;
        std::vector<unsigned int> subseq;
        for (auto b = a; b < k; b++) {
          if (a == b) {
            prev = 1;
            subseq.push_back(seq[b]);
          } else {
            auto lb = std::lower_bound(subseq.begin(), subseq.end(), seq[b]);
            if (*lb != seq[b]) {
              prev = prev + 1;
              subseq.insert(lb, seq[b]);
            }
          }
          sum += prev;
          // std::cout << a << "," << b << ":" << prev << "\n";
        }
        // for (auto x : subseq) {
        //   std::cout << x << ",";
        // }
        // std::cout << "\n";
      }
      std::cout << sum << "\n";
    }
  }
}
