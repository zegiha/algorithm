#include <iostream>

using namespace std;

int month, d, y, h, m, past_d;
double past_m, all_m;

const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const int normal_years_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int specific_years_day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void set_month(string t) {
  for(int i = 0; i < 12; i++) {
    if(t == months[i]) {
      month = i + 1;
      return;
    }
  }
}

void set_h_and_m(string t) {
  h = (t[0] - '0') * 10 + (t[1] - '0');
  m = (t[3] - '0') * 10 + (t[4] - '0');
}

bool is_specific_year(int y) {
  if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) {
    return true;
  }
  return false;
}

int main() {
  string t;

  cin >> t;
  set_month(t);

  cin >> t;
  d = stoi(t);

  cin >> t;
  y = stoi(t);

  cin >> t;
  set_h_and_m(t);

  if(!is_specific_year(y)) {
    for(int i = 0; i < month - 1; i++) {
      past_d += normal_years_day[i];
    }
    for(int i = 0; i < 12; i++) {
      all_m += normal_years_day[i] * 24 * 60;
    }
  } else {
    for(int i = 0; i < month - 1; i++) {
      past_d += specific_years_day[i];
    }
    for(int i = 0; i < 12; i++) {
      all_m += specific_years_day[i] * 24 * 60;
    }
  }
  past_d += d - 1;

  past_m = m + (h * 60) + (past_d * 24 * 60);
  printf("%0.10lf", past_m * 100 / all_m);
}