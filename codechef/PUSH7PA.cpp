#include <bits/stdc++.h>
typedef std::vector<long> Heights;
int
main()
{
  int tc;
  std::cin >> tc;
  while (tc--) {
    int len;
    std::cin >> len;
    Heights hts(len, 0);
    for (int i = 0; i < len; i++)
      std::cin >> hts[i];
    std::sort(hts.begin(), hts.end());
    long max_ht = 0;
    for (int i = 0; i < len; i++) {
      if (i - 1 >= 0 && hts[i - 1] == hts[i])
        continue;
      long curr_ht = 0;
      long jumps = 0;
      auto dup = hts[i];
      int n = 0;
      for (auto ub = std::upper_bound(hts.begin() + n, hts.end(), dup);
           ub != hts.end();
           ub = std::upper_bound(hts.begin() + n, hts.end(), dup)) {
        n = std::distance(hts.begin() + i, ub);
        curr_ht += n * (n + 1) / 2;
        jumps += n - 1;
        dup += 1;
      }
      max_ht = std::max(max_ht, curr_ht);
    }
    std::cout << max_ht << "\n";
  }
}
