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
  struct coord
  {
    long song;
    long pos;
  };
  struct coord_sort
  {
    bool operator()(const coord& a, const coord& b) const
    {
      return a.song < b.song;
    }
  };
  std::set<coord, coord_sort> seq{};

  long subseq_begin = 0, subseq_len = 0;
  for (auto sn = 0; sn < playlist_len; ++sn) {
    auto dup = seq.insert(coord{ songs[sn], sn });
    if (!dup.second) {
      subseq_begin = dup.first->pos;
      subseq_len = std::max(subseq_len, (long)seq.size());
      for (auto i = seq.begin(); i != seq.end();) {
        if (i->pos < subseq_begin) {
          i = seq.erase(i);
        } else {
          ++i;
        }
      }
    }
  }
  subseq_len = std::max(subseq_len, (long)seq.size());
  std::cout << subseq_len << "\n";
}
