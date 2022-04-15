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

  std::vector<std::vector<int>> state(n, std::vector<int>(m, 0));
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

  std::map<Coord, std::pair<char, Coord>> parents{
    { bgn, std::make_pair('?', Coord{ -1, -1 }) }
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
      if (state[c[0]][c[1]] & 1)
        continue;
      state[c[0]][c[1]] |= 1;
      parents[c] = std::make_pair(mv, point);
      upcoming.push(c);
    }
    state[point[0]][point[1]] |= (1 << 2);
    if (plan[point[0]][point[1]] == 'B')
      break;
  }

  std::string moves{};
  if (state[dst[0]][dst[1]] & (1 << 2)) {
    std::cout << "YES\n";
    for (auto par = parents[dst]; par.second != Coord{ -1, -1 };
         par = parents[par.second]) {
      moves.insert(moves.begin(), par.first);
    }
    std::cout << moves.length() << "\n";
    std::cout << moves << "\n";
  } else {
    std::cout << "NO\n";
  }
}
