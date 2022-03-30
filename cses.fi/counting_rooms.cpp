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

  auto nearest_edges = [](const auto p) {
    const auto [x, y] = p;
    return std::array<std::pair<int, int>, 4>{ std::make_pair(x, y + 1),
                                               std::make_pair(x, y - 1),
                                               std::make_pair(x - 1, y),
                                               std::make_pair(x + 1, y) };
  };
  std::deque<std::pair<int, int>> upcoming{ std::make_pair(0, 0) };
  while (!upcoming.empty()) {
    auto point = upcoming.front();
    auto neighb = nearest_edges(point);
    for (auto t : neighb) {
    }
  }
}
