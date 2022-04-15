#include <bits/stdc++.h>

struct Coord
{
  int i, j;
};
auto constexpr
operator!=(const Coord& lhs, const Coord& rhs) -> bool
{
  return lhs.i != rhs.i || lhs.j != rhs.j;
}
auto constexpr
operator==(const Coord& lhs, const Coord& rhs) -> bool
{
  return lhs.i == rhs.i && lhs.j == rhs.j;
}
auto constexpr
operator<(const Coord& lhs, const Coord& rhs) -> bool
{
  return (lhs.i * lhs.i + lhs.j * lhs.j) < (rhs.i * rhs.i + rhs.j * rhs.j);
}
int
main()
{
  int n, m;
  auto bgn = Coord{ -1, -1 }, dst = Coord{ -1, -1 };
  std::cin >> n >> m;
  std::vector<std::string> plan(n, "");
  for (int i = 0; i < n; i++) {
    std::cin >> plan[i];
    if (bgn.i == -1) {
      if (auto bgn_pot = plan[i].find('A'); bgn_pot != std::string::npos) {
        bgn = { i, static_cast<int>(bgn_pot) };
      }
    }
    if (dst.i == -1) {
      if (auto dst_pot = plan[i].find('B'); dst_pot != std::string::npos) {
        dst = { i, static_cast<int>(dst_pot) };
      }
    }
  }

  auto neighbours = [](const auto o) {
    return std::array<std::pair<char, Coord>, 4>{
      std::make_pair('R', Coord{ o.i, o.j + 1 }),
      std::make_pair('L', Coord{ o.i, o.j - 1 }),
      std::make_pair('D', Coord{ o.i + 1, o.j }),
      std::make_pair('U', Coord{ o.i - 1, o.j })
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
  std::deque<Coord> upcoming{ bgn };
  while (!upcoming.empty()) {
    auto point = upcoming.front();
    upcoming.pop_front();
    for (auto e : neighbours(point)) {
      const auto [mv, c] = e;
      if (oob(c))
        continue;
      if (auto& [_a, _b, dis] = state[c]; dis & 1) {
        continue;
      }
      upcoming.push_back(c);
      state[c] = std::make_tuple(mv, point, 1);
    }
    char mv;
    Coord par;
    std::tie(mv, par, std::ignore) = state[point];
    state[point] = std::make_tuple(mv, par, 2);
    if (plan[point.i][point.j] == 'B')
      break;
  }

  char mv;
  Coord par;
  int found;
  std::tie(mv, par, found) = state[dst];
  std::string moves{};
  if (found == 2) {
    std::cout << "YES\n";
    for (; par != bgn; std::tie(mv, par, found) = state[par]) {
      moves.push_back(mv);
    }
    std::cout << moves.length() << "\n";
    std::cout << moves << "\n";
  } else {
    std::cout << "NO\n";
  }
}
