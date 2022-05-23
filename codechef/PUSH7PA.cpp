#include <bits/stdc++.h>
typedef std::vector<long long> Heights;
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
    long long cont_ht = 0, hi, lo = 0, val = hts[0];
    for (hi = 0; hi < len; hi++) {
      if (hts[hi] != hts[lo]) {
        long long n = hi - lo, sum = val + n - 1;
        cont_ht = std::max(cont_ht, sum);
        lo = hi;
        val = hts[lo];
      }
    }
    cont_ht = std::max(cont_ht, (hi - lo));
    {
      long long n = hi - lo, sum = hts[lo] + n - 1;
      cont_ht = std::max(cont_ht, sum);
    }

    std::cout << cont_ht << "\n";
  }
}
