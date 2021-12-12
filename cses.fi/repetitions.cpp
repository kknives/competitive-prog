#include <bits/stdc++.h>

auto
main() -> int
{
  std::string sequence{};
  std::cin >> sequence;

  long max_rep = 0, rep = 0;
  char prev = '?';
  for (long i = 0; i < sequence.size(); i++) {
    if (prev == sequence[i]) {
      rep++;
    } else if (rep != 0) {
      if (max_rep < rep)
        max_rep = rep;
      rep = 0;
    }
    prev = sequence[i];
  }
  if (max_rep < rep)
    max_rep = rep;
  max_rep++;
  std::cout << max_rep << std::endl;
}
