#include <bits/stdc++.h>

// Only for debugging
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

  auto plan = static_cast<char*>(malloc(n * m * sizeof(char)));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      std::cin >> *(plan + i * m + j);
  }

  auto nearest_edges = [](const auto p) {
    const auto [x, y] = p;
    return std::array<std::pair<int, int>, 4>{ std::make_pair(x, y + 1),
                                               std::make_pair(x, y - 1),
                                               std::make_pair(x - 1, y),
                                               std::make_pair(x + 1, y) };
  };
  auto state = static_cast<int*>(malloc(n * m * sizeof(int)));
  auto oob_gen = [](int l, int b) {
    return [l, b](const auto t) {
      const auto [x, y] = t;
      auto lower = x >= 0 && y >= 0;
      auto upper = x < l && y < b;
      return (!lower) || (!upper);
    };
  };
  auto oob = oob_gen(n, m);
  int num_rooms = 0;
  for (int i = 0; i < n * m; i++) {
    if ((*(state + i) & 1))
      continue;
    if (*(plan + i) == '.') {
      std::deque<std::pair<int, int>> upcoming{ std::make_pair(i / m, i % m) };
      while (!upcoming.empty()) {
        auto point = upcoming.front();
        upcoming.pop_front();
        auto neighb = nearest_edges(point);
        for (auto t : neighb) {
          if (oob(t))
            continue;
          if (!(*(state + t.first * m + t.second) & 1)) {
            if (*(plan + t.first * m + t.second) == '.') {
              upcoming.push_front(t);
            }
            *(state + t.first * m + t.second) |= 1;
          }
        }
      }
      *(state + i) |= 1 << 2;
      ++num_rooms;
    }
  }

  std::cout << num_rooms << "\n";
}
