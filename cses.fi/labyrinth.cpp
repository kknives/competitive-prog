#include <bits/stdc++.h>

int
main()
{
  int n, m;
  int bgn[2] = { -1, -1 }, dst[2] = { -1, -1 };
  std::cin >> n >> m;
  std::vector<std::string> plan(n, "");
  for (int i = 0; i < n; i++) {
    std::cin >> plan[i];
    if (bgn[0] == -1) {
      if (auto bgn_pot = plan[i].find('A'); bgn_pot != std::string::npos) {
        bgn[0] = i;
        bgn[1] = bgn_pot;
      }
    }
    if (dst[0] == -1) {
      if (auto dst_pot = plan[i].find('B'); dst_pot != std::string::npos) {
        dst[0] = i;
        dst[1] = dst_pot;
      }
    }
  }

  std::cout << "Done\n";
}
