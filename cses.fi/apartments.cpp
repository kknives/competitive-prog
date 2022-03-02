#include <bits/stdc++.h>

auto
main() -> int
{
  long pref_count, size_count, tol;
  std::cin >> pref_count;
  std::cin >> size_count;
  std::cin >> tol;

  std::vector<long> prefs{}, sizes{};
  for (int pc = 0; pc < pref_count; pc++) {
    long i;
    std::cin >> i;
    prefs.push_back(i);
  }
  for (int sc = 0; sc < size_count; sc++) {
    long i;
    std::cin >> i;
    sizes.push_back(i);
  }

  std::sort(prefs.begin(), prefs.end());
  std::sort(sizes.begin(), sizes.end());

  long granted = 0;
  auto slice_begin = sizes.begin();
  for (long i = 0; i < pref_count; i++) {
    auto f = std::lower_bound(
      slice_begin, sizes.end(), prefs[i], [tol](const long& y, long x) {
        return std::abs(y - x) > tol;
      });

    std::cout << *f << "\n";
    if (f != sizes.end()) {
      granted++;
      // slice_begin = std::next(f, 1);
    }
  }

  std::cout << granted << "\n";
}
