#include <bits/stdc++.h>

auto
main() -> int
{
  long playlist_len;
  std::cin >> playlist_len;

  std::vector<long> songs{};
  for (auto sc = 0; sc < playlist_len; sc++) {
    long i;
    std::cin >> i;
    songs.push_back(i);
  }
  std::vector<long> track_num(playlist_len);
  std::iota(track_num.begin(), track_num.end(), 0);
  auto coord_sort = [&songs](const long& a, const long& b) {
    return songs[a] < songs[b];
  };
  std::sort(track_num.begin(), track_num.end(), coord_sort);
  long last_ign = 0;
  // for (auto x : track_num) {
  //   std::cout << x << " ";
  // }
  // std::cout << "\n";

  long subseq_begin = 0, subseq_len = 0;
  std::deque<long> seq{};
  for (auto sn = 0; sn < playlist_len; ++sn) {
    // std::cout << "song# " << sn << ":" << subseq_begin
    //           << " of len: " << subseq_len << "\n";

    auto tn =
      std::lower_bound(track_num.begin(), track_num.end(), sn, coord_sort);
    if (std::next(tn) == track_num.end()) {
      last_ign = sn;
      continue;
    }
    if (songs[*std::next(tn)] != songs[sn]) {
      last_ign = sn;
      continue;
    }
    for (auto dup_tn = tn;
         dup_tn != track_num.end() && songs[*dup_tn] == songs[sn];
         std::advance(dup_tn, 1)) {
      if (*dup_tn >= subseq_begin && *dup_tn < sn) {
        auto other_dup =
          std::lower_bound(seq.begin(), seq.end(), songs[*dup_tn]);
        // std::cout << "found in seq: " << *other_dup << "\n";
        seq.erase(seq.begin(), other_dup);
        // for (auto x : seq) {
        //   std::cout << " " << x;
        // }
        // std::cout << "\n";
        // std::cout << "Seq front: " << seq.empty() << "\n";
        subseq_len = std::max(subseq_len, sn - subseq_begin);
        if (seq.empty()) {
          ++subseq_begin;
        } else {
          subseq_begin = seq.front() + 1;
          seq.pop_front();
        }
        break;
      }
    }
    seq.push_back(sn);
  }
  // std::cout << "last ignored " << last_ign << "\n";
  if (subseq_begin == 0 && seq.size() == 0) {
    // std::cout << "Spl bdry#1 \n";
    subseq_len = playlist_len;
  } else if (last_ign == playlist_len - 1) {
    // std::cout << "Spl bdry#2 \n";
    subseq_len = std::max(subseq_len, playlist_len - subseq_begin);
  }
  std::cout << subseq_len << "\n";
}
