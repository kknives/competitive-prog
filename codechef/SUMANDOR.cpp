#include <bits/stdc++.h>
auto
seq_len(long or_sum, long sum) -> long;

auto
main() -> int
{
  int cases;
  std::cin >> cases;

  for (int tc = 0; tc < cases; tc++) {
    long or_sum, sum;
    std::cin >> or_sum;
    std::cin >> sum;

    std::cout << seq_len(or_sum, sum) << "\n";
  }
  return 0;
}

auto
gcd_meth(long or_sum, long sum) -> long
{
  long terms = 1;
  for (auto i = sum; i > 0; i >>= 1) {
    if ((i | or_sum) == or_sum) {
      std::cout << i << "\n";
      terms++;
      break;
    }
    if ((i & or_sum) != 0) {
      std::cout << (i & or_sum) << "\n";
      i -= i & or_sum;
      terms++;
    }
  }
  return terms;
}

auto
seq_len(long or_sum, long sum) -> long
{
  long seq = 0;
  if ((sum | or_sum) == or_sum) {
    seq = (sum == 0 ? 0 : 1);
  } else if (((sum % or_sum) | or_sum) == or_sum) {
    seq = seq_len(or_sum, sum % or_sum) + (sum / or_sum);
  } else if ((or_sum % 2) != (sum % 2)) {
    seq = -1;
  } else {
    seq = gcd_meth(or_sum, sum);
  }
  return seq;
}
// auto rcr_seq_len(long div, resp in) -> resp {
//   auto mismatch = in.quo^div;
//   if (mismatch > div) {
//     auto scale = __builtin_ctz(mismatch);
//     in.residue += scale * (in.quo % (1 << scale));
//     assert((in.residue | div) == div);
//     return rcr_seq_len(div, in);
//   }
//   else {
//     in.residue += div - quo;
//   }
// }
