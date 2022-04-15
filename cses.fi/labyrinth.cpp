#include <bits/stdc++.h>

typedef std::array<int, 2> Coord;
int
main()
{
  int n, m;
  auto bgn = Coord{ -1, -1 }, dst = Coord{ -1, -1 };
  std::cin >> n >> m;
  std::vector<std::string> plan(n, "");
  for (int i = 0; i < n; i++) {
    std::cin >> plan[i];
    if (bgn[0] == -1) {
      if (auto bgn_pot = plan[i].find('A'); bgn_pot != std::string::npos) {
        bgn = { i, static_cast<int>(bgn_pot) };
      }
    }
    if (dst[0] == -1) {
      if (auto dst_pot = plan[i].find('B'); dst_pot != std::string::npos) {
        dst = { i, static_cast<int>(dst_pot) };
      }
    }
  }

  auto neighbours = [](const auto o) {
    return std::array<std::pair<char, Coord>, 4>{
      std::make_pair('R', Coord{ o[0], o[1] + 1 }),
      std::make_pair('L', Coord{ o[0], o[1] - 1 }),
      std::make_pair('D', Coord{ o[0] + 1, o[1] }),
      std::make_pair('U', Coord{ o[0] - 1, o[1] })
    };
  };
  auto oob_gen = [](const auto r, const auto c) {
    return [r, c](const Coord p) {
      const auto [x, y] = p;
      auto lower = x >= 0 && y >= 0;
      auto upper = x < r && y < c;
      return (!lower) || (!upper);
    };
  };
  auto oob = oob_gen(n, m);

  std::map<Coord, std::tuple<char, Coord, int>> state{
    { bgn, std::make_tuple('?', Coord{ -1, -1 }, 1) }
  };
  std::queue<Coord> upcoming{};
  upcoming.push(bgn);
  while (!upcoming.empty()) {
    auto point = upcoming.front();
    upcoming.pop();
    for (auto e : neighbours(point)) {
      const auto [mv, c] = e;
      if (oob(c))
        continue;
      if (plan[c[0]][c[1]] == '#')
        continue;
      if (auto res = state.insert({ c, std::make_tuple(mv, point, 1) });
          !res.second)
        continue;
      upcoming.push(c);
    }
    char mv;
    Coord par;
    int found;
    std::tie(mv, par, found) = state[point];
    state[point] = std::make_tuple(mv, par, found | (1 << 2));
    if (plan[point[0]][point[1]] == 'B')
      break;
  }

  char mv;
  Coord par;
  int found;
  std::tie(mv, par, found) = state[dst];
  std::string moves{};
  if (found & (1 << 2)) {
    std::cout << "YES\n";
    for (; par != Coord{ -1, -1 }; std::tie(mv, par, found) = state[par]) {
      moves.insert(moves.begin(), mv);
    }
    std::cout << moves.length() << "\n";
    std::cout << moves << "\n";
  } else {
    std::cout << "NO\n";
  }
}
