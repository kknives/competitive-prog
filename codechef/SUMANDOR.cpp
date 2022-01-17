#include <bits/stdc++.h>
auto
seq_len(uint32_t or_sum, uint32_t sum) -> long;

auto
main() -> int
{
  int cases;
  std::cin >> cases;

  for (int tc = 0; tc < cases; tc++) {
    uint32_t or_sum, sum;
    std::cin >> or_sum;
    std::cin >> sum;

    std::cout << seq_len(or_sum, sum) << "\n";
  }
  return 0;
}

auto
gd_seq_len(uint32_t or_sum, uint32_t sum) -> uint32_t
{
  std::vector<uint32_t> seq{};
  auto div = or_sum;
  for (auto i = sum; i > 0;) {
    auto pow = 1u << (31 - __builtin_clz(div));
    if (pow > i)
      break;
    std::cout << pow << "\n";
    seq.push_back(i / pow);
    i -= pow * (i / pow);
    div &= ~pow;
  }
  // for (auto x : seq)
  //   std::cout << x << " ";
  auto res = 0;
  if (div == 0) {
    res = *std::max_element(seq.begin(), seq.end());
  }
  return res;
}

auto
seq_len(uint32_t or_sum, uint32_t sum) -> long
{
  auto seq_l = 0;
  if (((sum % or_sum) | or_sum) == or_sum) {
    seq_l = (sum / or_sum) + ((sum % or_sum) == 0 ? 0 : 1);
    // } else if ((or_sum % 2 != 0) && (sum % 2 == 0)) {
    //   auto low = 2u;
    //   auto rest = gd_seq_len(or_sum - 1, sum - low);
    //   // std::cout << "rest,low" << rest << "," << low << "\n";
    //   seq_l = (rest > 0) ? std::max(low, rest) : -1;
    //   // seq_l = std::max(low, gd_seq_len(or_sum - 1, sum - low));
  } else {
    seq_l = gd_seq_len(or_sum, sum);
    seq_l = (seq_l > 0) ? seq_l : -1;
  }
  return seq_l;
}
