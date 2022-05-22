#include <bits/stdc++.h>
typedef long long llint;

int
main()
{
  int len_r, queries;
  std::cin >> len_r >> queries;
  std::vector<llint> range(len_r, 0);
  std::vector<llint> pfx_sum(len_r, 0);
  std::cin >> range[0];
  pfx_sum[0] = range[0];
  for (int i = 1; i < len_r; i++) {
    std::cin >> range[i];
    pfx_sum[i] = pfx_sum[i - 1] + range[i];
  }
  for (int t = 0; t < queries; t++) {
    int a, b;
    std::cin >> a >> b;
    llint low_sum = pfx_sum[a - 1], hi_sum = pfx_sum[b - 1],
          diff = hi_sum - low_sum + range[a - 1];
    std::cout << diff << "\n";
  }
}
