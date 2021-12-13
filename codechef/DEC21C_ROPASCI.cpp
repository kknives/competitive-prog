#include <bits/stdc++.h>

auto
bitvec_m(std::string&) -> void;
auto
quad_m(std::string match) -> char;

auto
main(int argc, char* argv[]) -> int
{
  int cases;
  std::cin >> cases;

  for (int tc = 0; tc < cases; tc++) {
    int player_count;
    std::cin >> player_count;
    std::string moves{};
    std::cin >> moves;

    // bitvec_m(moves);
    std::vector<int> rocks{}, papers{}, scisrs{};
    for (int i = 0; i < moves.size(); i++) {
      switch (moves[i]) {
        case 'R':
          rocks.push_back(i);
          break;
        case 'P':
          papers.push_back(i);
          break;
        case 'S':
          scisrs.push_back(i);
          break;
      }
    }
    // for (auto x : rocks)
    // std::cout << x << ',';
    // std::cout << ":R\n";
    // for (auto x : papers)
    // std::cout << x << ',';
    // std::cout << ":P\n";
    // for (auto x : scisrs)
    // std::cout << x << ',';
    // std::cout << ":S\n";

    std::string w_moves(player_count, '?');
    w_moves[player_count - 1] = moves[player_count - 1];
    for (int i = moves.size() - 2; i >= 0; i--) {
      char play = moves[i];
      auto r_iter = std::upper_bound(rocks.begin(), rocks.end(), i);
      auto p_iter = std::upper_bound(papers.begin(), papers.end(), i);
      auto s_iter = std::upper_bound(scisrs.begin(), scisrs.end(), i);

      for (int j = i; j < moves.size(); j++) {
        // std::cout << j << std::endl;
        // std::cout << "Iters " << *r_iter << ',' << *p_iter << ',' << *s_iter
        // << '\n';
        switch (play) {
          case 'R':
            if (p_iter == papers.end()) {
              j = moves.size();
              continue;
            }
            j = *p_iter;
            r_iter = std::upper_bound(r_iter, rocks.end(), j);
            s_iter = std::upper_bound(s_iter, scisrs.end(), j);
            play = 'P';
            break;
          case 'P':
            if (s_iter == scisrs.end()) {
              j = moves.size();
              continue;
            }
            j = *s_iter;
            r_iter = std::upper_bound(r_iter, rocks.end(), j);
            p_iter = std::upper_bound(p_iter, papers.end(), j);
            play = 'S';
            break;
          case 'S':
            if (r_iter == rocks.end()) {
              j = moves.size();
              continue;
            }
            j = *r_iter;
            p_iter = std::upper_bound(p_iter, papers.end(), j);
            s_iter = std::upper_bound(s_iter, scisrs.end(), j);
            play = 'R';
            break;
        }
        if (w_moves[j] != '?') {
          play = w_moves[j];
          break;
        }
      }
      w_moves[i] = play;
    }

    std::cout << w_moves << '\n';
  }
}

auto
quad_m(std::string match) -> char
{
  char play = match.front();
  for (int i = 1; i < match.size(); i++) {
    if (play == match[i])
      continue;
    switch (match[i]) {
      case 'R':
        play = (play == 'S') ? 'R' : 'P';
        break;
      case 'P':
        play = (play == 'R') ? 'P' : 'S';
        break;
      case 'S':
        play = (play == 'P') ? 'S' : 'R';
        break;
    }
  }
  return play;
}

auto
bitvec_m(std::string moves) -> void
{
  int player_count = moves.size();
  int loc[3] = { 0, 0, 0 }; // R P S
  int& rocks = loc[0];
  int& papers = loc[1];
  int& scisrs = loc[2];
  char prev = '?';
  for (int i = 0; i < moves.size(); i++) {
    if (prev == moves[i])
      continue;
    switch (moves[i]) {
      case 'R':
        rocks |= (1 << i);
        break;
      case 'P':
        papers |= (1 << i);
        break;
      case 'S':
        scisrs |= (1 << i);
        break;
    }
    prev = moves[i];
  }
  std::cout << rocks << ", " << papers << ", " << scisrs << std::endl;

  std::string w_moves(moves.size(), '?');
  for (int i = 0; i < moves.size() - 1; i++) {
    char play = moves[i];
    for (int j = i; j < moves.size(); j++) {
      std::cout << j << std::endl;
      switch (play) {
        case 'R':
          j += __builtin_ctz(papers >> j) - 1;
          play = (moves.size() <= (j)) ? play : 'P';
          break;
        case 'P':
          j += __builtin_ctz(scisrs >> j) - 1;
          play = (moves.size() <= (j)) ? play : 'S';
          break;
        case 'S':
          j += __builtin_ctz(rocks >> j) - 1;
          play = (moves.size() <= (j)) ? play : 'R';
          break;
      }
    }
    w_moves[i] = play;
  }
  w_moves[player_count - 1] = moves[player_count - 1];
  std::cout << w_moves << '\n';
}
