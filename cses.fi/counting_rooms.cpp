#include <bits/stdc++.h>

auto
print_array(int* mat, int n, int m) -> void
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", static_cast<int>(*(mat + i * m + j)));
    }
    printf("\n");
  }
}
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
  int* state = static_cast<int*>(malloc(n * m * sizeof(int)));
  *(state) = 1;
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
      if (!(*(state + t.first * m + t.second) & 1)) {
        if (plan[t.first][t.second] == '.') {
          upcoming.push_front(t);
        } else {
          upcoming.push_back(t);
        }
        *(state + t.first * m + t.second) |= 1;
      }
    }
    if (plan[point.first][point.second] == '#') {
      inside_room = false;
      *(state + point.first * m + point.second) |= 1 << 3;
      continue;
    }
    // There's a bug here. All blocks are processed, but the count is off
    if (!inside_room) {
      ++num_rooms;
      inside_room = true;
      *(state + point.first * m + point.second) |= 1 << 2;
      continue;
    }
    *(state + point.first * m + point.second) = 7;
  }

  std::cout << num_rooms << "\n";
}
