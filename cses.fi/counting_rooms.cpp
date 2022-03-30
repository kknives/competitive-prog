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
  std::vector<std::vector<int>> state(n, std::vector<int>(m, 0));
  auto oob_gen = [](int l, int b) {
    return [l, b](const auto t) {
      const auto [x, y] = t;
      auto lower = x >= 0 && y >= 0;
      auto upper = x < l && y < b;
      return (!lower) || (!upper);
    };
  };
  auto oob = oob_gen(n, m);
  bool inside_room = false;
  int num_rooms = 0;
  while (!upcoming.empty()) {
    auto point = upcoming.front();
    upcoming.pop_front();
    auto neighb = nearest_edges(point);
    for (auto t : neighb) {
      if (oob(t))
        continue;
      if (!(state[t.first][t.second] & 1)) {
        if (plan[t.first][t.second] == '.') {
          upcoming.push_front(t);
        } else {
          upcoming.push_back(t);
        }
        state[t.first][t.second] |= 1;
      }
    }
    if (plan[point.first][point.second] == '#') {
      inside_room = false;
      continue;
    }
    if (!inside_room) {
      ++num_rooms;
      inside_room = true;
    }
    state[point.first][point.second] |= 1 << 2;
  }

  std::cout << num_rooms << "\n";
}
