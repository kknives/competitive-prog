#include <bits/stdc++.h>

auto
main() -> int
{
  int n, m;
  std::cin >> n;
  std::cin >> m;

  std::vector<std::vector<char>> plan(n, std::vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      std::cin >> plan[i][j];
  }

  std::deque<std::tuple<int, int>> upcoming{ std::make_pair(0, 0) };
  while (!upcoming.empty()) {
    auto [x, y] = upcoming.front();

    if (plan[x][y] == '.') {
    }
  }
}
