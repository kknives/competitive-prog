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
  std::sort(
    track_num.begin(), track_num.end(), [&songs](const long& a, const long& b) {
      return songs[a] < songs[b];
    });
  for (auto x : track_num) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  long subseq_begin = 0, subseq_end = 0;
  for (auto tn = 0; tn < playlist_len; tn++) {
    std::cout << subseq_begin << ":" << subseq_end << "\n";
    std::cout << "track#" << track_num[tn] << "\n";
    if (track_num[tn] == track_num.back())
      break;
    auto track = track_num[tn];
    auto next_track = track_num[tn + 1];

    if (songs[track] != songs[next_track])
      continue;
    auto subseq_len = subseq_end - subseq_begin;
    if (track - subseq_begin < subseq_len &&
        subseq_end - next_track < subseq_len) {
      subseq_begin = track;
      subseq_end = next_track;
      continue;
    }
    auto cand_len = next_track - track;
    if (subseq_len < cand_len) {
      subseq_begin = track;
      subseq_end = next_track;
    }
  }

  std::cout << subseq_end - subseq_begin << "\n";
}
