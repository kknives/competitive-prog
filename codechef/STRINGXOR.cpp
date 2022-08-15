#include <bits/stdc++.h>

std::string results[] = { "NO", "YES" };

int
bt(const int len, char* init, char* fin, int w)
{
  if (w > len)
    return true;
  if (init[w] == fin[w])
    return bt(len, init, fin, w + 1);
  else {
    char temp_b, temp_f;
    int chg;
    int back_res = false;
    if ((w > 0) && (((init[w] == init[w - 1]) && (fin[w] == fin[w - 1])) ||
                    (init[w] != init[w - 1]))) {
      temp_b = init[w - 1], temp_f = init[w];
      chg = (init[w - 1] - '0') ^ (init[w] - '0');
      init[w] = chg + '0';
      init[w - 1] = chg + '0';
      back_res = bt(len, init, fin, w - 1);
      init[w - 1] = temp_b;
      init[w] = temp_f;
    }
    if (back_res)
      return back_res;

    int forw_res = false;
    if ((w < len - 1) &&
        (((init[w] == init[w + 1]) && (fin[w] == fin[w + 1])) ||
         (init[w] != init[w + 1]))) {
      temp_b = init[w];
      temp_f = init[w + 1];
      chg = (init[w] - '0') ^ (init[w + 1] - '0');
      init[w] = chg + '0';
      init[w + 1] = chg + '0';
      forw_res = bt(len, init, fin, w);
      init[w] = temp_b;
      init[w + 1] = temp_f;
    }

    return back_res || forw_res;
  }
}
int
transform(const int len, char* init, char* fin)
{
  if (len == 1)
    return init[0] == fin[0];
  if (len <= 0)
    return 0;
  int init_pair = (init[0] - '0') + (init[1] - '0' << 1);
  int fin_pair = (fin[0] - '0') + (fin[1] - '0' << 1);

  switch (init_pair) {
    case 0b00:
      return ((fin_pair == 0b00)) && transform(len - 2, init + 2, fin + 2);
    case 0b01:
      return ((fin_pair == 0b00) || (fin_pair == 0b11) || (fin_pair == 0b01)) &&
             transform(len - 2, init + 2, fin + 2);
    case 0b10:
      return ((fin_pair == 0b10) || (fin_pair == 0b00) || (fin_pair == 0b11)) &&
             transform(len - 2, init + 2, fin + 2);
    case 0b11:
      return ((fin_pair == 0b00) || (fin_pair == 0b11)) &&
             transform(len - 2, init + 2, fin + 2);
    default:
      return false;
  }
}
int
main()
{
  int tc;
  std::cin >> tc;
  while (tc--) {
    int len;
    char *init, *fin;
    scanf("%d\n%ms\n%ms", &len, &init, &fin);
    std::cout << results[bt(len, init, fin, 0)] << "\n";
  }
  return 0;
}
