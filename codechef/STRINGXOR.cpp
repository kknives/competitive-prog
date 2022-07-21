#include <bits/stdc++.h>

std::string results[] = { "NO", "YES" };
int
transform(int from, int to)
{
  switch (from) {
    case 0b00:
      return to == 0b00;
    case 0b01:
      return ((to == 0b00) || (to == 0b11) || (to == 0b01));
    case 0b10:
      return ((to == 0b10) || (to == 0b00) || (to == 0b11));
    case 0b11:
      return ((to == 0b00) || (to == 0b11));
    default:
      return false;
  }
}
int
main()
{
  int tc;
  std::cin >> tc;
  while (tc--) {
    int len;
    std::string init{}, fin{};
    std::cin >> len >> init >> fin;
    int res = 0;
    for (int i = 0; i < len; i++) {
      if (init[i] == fin[i])
        res = 1;
      else if (i + 1 == len) {
        int bac_init_pair = (init[i - 1] - '0') + (init[i] - '0' << 1);
        int bac_fin_pair = (fin[i - 1] - '0') + (fin[i] - '0' << 1);
        res = transform(bac_init_pair, bac_fin_pair);
      }

      else if (i == 0) {
        int for_fin_pair = (fin[i + 1] - '0') + (fin[i] - '0' << 1);
        int for_init_pair = (init[i + 1] - '0') + (init[i] - '0' << 1);
        res = transform(for_init_pair, for_fin_pair);
      } else {
        int for_init_pair = (init[i + 1] - '0') + (init[i] - '0' << 1);
        int bac_init_pair = (init[i] - '0') + (init[i - 1] - '0' << 1);
        int for_fin_pair = (fin[i + 1] - '0') + (fin[i] - '0' << 1);
        int bac_fin_pair = (fin[i] - '0') + (fin[i - 1] - '0' << 1);

        res = transform(for_init_pair, for_fin_pair) ||
              transform(bac_init_pair, bac_fin_pair);
      }
      if (res == 0)
        break;
    }
    std::cout << results[res] << "\n";
  }
  return 0;
}
