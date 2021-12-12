#include <bits/stdc++.h>

auto
count_moves(long) -> long;
int
main()
{
  long n;
  std::cin >> n;

  long i;
  std::cin >> i;
  std::cout << count_moves(i) << std::endl;
}
auto
count_moves(long prev) -> long
{
  long this_i;
  if (std::cin >> this_i) {
    long diff = this_i - prev;
    if (diff < 0) {
      return count_moves(prev) - diff;
    } else {
      return count_moves(this_i);
    }
  } else {
    return 0;
  }
}
