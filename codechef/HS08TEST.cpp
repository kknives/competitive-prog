#include <bits/stdc++.h>

auto
trxn(double bal, int wdw) -> double
{
  double after = bal;
  if (wdw % 5 != 0) {
  } else if (bal >= (wdw + 0.5)) {
    after -= wdw + 0.5;
  }
  return after;
}
auto
main() -> int
{
  int wdw;
  double bal;
  std::cin >> wdw;
  std::cin >> bal;
  std::cout << std::setprecision(2) << std::fixed << trxn(bal, wdw);
}
