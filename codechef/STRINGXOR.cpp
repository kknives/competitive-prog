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
transform(const int len, char* init, char* fin, int w)
{
  if (w > len)
    return true;
  if (init[w] == fin[w])
    return transform(len, init, fin, w + 1);

  int forw_res = false;
  int back_res = false;
  char temp_b, temp_f;
  int chg;
  if (w < len - 1) {
    int init_pair = (init[w] - '0') + ((init[w + 1] - '0') << 1);
    int fin_pair = (fin[w] - '0') + ((fin[w + 1] - '0') << 1);

    temp_b = init[w];
    temp_f = init[w + 1];
    chg = (init[w] - '0') ^ (init[w + 1] - '0');
    init[w] = chg + '0';
    init[w + 1] = chg + '0';
    switch (init_pair) {
      case 0b00:
        forw_res = ((fin_pair == 0b00)) && transform(len, init, fin, w);
        break;
      case 0b01:
        forw_res =
          ((fin_pair == 0b00) || (fin_pair == 0b11) || (fin_pair == 0b10)) &&
          transform(len, init, fin, w);
        break;
      case 0b10:
        forw_res =
          ((fin_pair == 0b01) || (fin_pair == 0b00) || (fin_pair == 0b11)) &&
          transform(len, init, fin, w);
        break;
      case 0b11:
        forw_res = ((fin_pair == 0b00) || (fin_pair == 0b11)) &&
                   transform(len, init, fin, w);
        break;
    }
    init[w] = temp_b;
    init[w + 1] = temp_f;
    if (forw_res)
      return forw_res;
  } else if (w > 0) {
    int init_pair = (init[w - 1] - '0') + ((init[w] - '0') << 1);
    int fin_pair = (fin[w - 1] - '0') + ((fin[w] - '0') << 1);
    temp_b = init[w - 1];
    temp_f = init[w];
    chg = (init[w - 1] - '0') ^ (init[w] - '0');
    init[w] = chg + '0';
    init[w - 1] = chg + '0';

    switch (init_pair) {
      case 0b00:
        back_res = ((fin_pair == 0b00)) && transform(len, init, fin, w - 1);
        break;
      case 0b01:
        back_res =
          ((fin_pair == 0b00) || (fin_pair == 0b11) || (fin_pair == 0b10)) &&
          transform(len, init, fin, w - 1);
        break;
      case 0b10:
        back_res =
          ((fin_pair == 0b01) || (fin_pair == 0b00) || (fin_pair == 0b11)) &&
          transform(len, init, fin, w - 1);
        break;
      case 0b11:
        back_res = ((fin_pair == 0b00) || (fin_pair == 0b11)) &&
                   transform(len, init, fin, w - 1);
        break;
    }
    init[w - 1] = temp_b;
    init[w] = temp_f;
  }
  return back_res;
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
    std::cout << results[transform(len, init, fin, 0)] << "\n";
  }
  return 0;
}
