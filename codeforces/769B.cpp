#include <bits/stdc++.h>

int
main()
{
  int len;
  std::cin >> len;
  std::vector<int> awk(len);
  std::vector<int> awk_ref(len);
  std::vector<std::string> play{};

  for (int i = 0; i < len; i++) {
    awk_ref[i] = i;
    std::cin >> awk[i];
  }

  std::sort(awk_ref.begin() + 1, awk_ref.end(), [&awk](int a, int b) {
    return awk[a] > awk[b];
  });
  int from = 0, to = 1;
  for (int i = 0; i < len; i++) {
    from = awk_ref[i];
    if (awk[from] == 0)
      break;
    while (awk[from] > 0 && (to < len)) {
      std::stringstream s;
      s << from + 1 << " " << awk_ref[to] + 1;
      play.push_back(s.str());
      to++;
      awk[from]--;
    }
  }
  if (to >= len) {
    std::cout << play.size() << "\n";
    for (auto s : play)
      std::cout << s << "\n";
  } else
    std::cout << "-1";
}
