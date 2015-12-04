#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

void part1(vector<char>& input) {
  map<pair<int,int>, int> houses;
  int santa_row = 0, santa_col = 0;
  for (auto& value : input) {
    switch(value) {
      case '>':
        santa_row++;
        break;
      case '<':
        santa_row--;
        break;
      case '^':
        santa_col++;
        break;
      case 'v':
        santa_col--;
        break;
      default:
       exit(1);
    }
    houses[make_pair(santa_row, santa_col)] = 1;
  }
  cout << "Num houses with just santa: " << houses.size() << endl;
}

void part2(vector<char>& input) {
  map<pair<int,int>, int> houses;
  bool flag = false;
  int santa_row = 0, santa_col = 0, robo_row = 0, robo_col = 0;
  for (auto& value: input) {
    if (!flag) {
      switch(value) {
        case '>':
          santa_row++;
          break;
        case '<':
          santa_row--;
          break;
        case '^':
          santa_col++;
          break;
        case 'v':
          santa_col--;
          break;
        default:
         exit(1);
      }
      houses[make_pair(santa_row, santa_col)] = 1;
    }
    if (flag) {
      switch(value) {
        case '>':
          robo_row++;
          break;
        case '<':
          robo_row--;
          break;
        case '^':
          robo_col++;
          break;
        case 'v':
          robo_col--;
          break;
        default:
         exit(1);
      }
      houses[make_pair(robo_row, robo_col)] = 1;
    }
    flag = !flag;
  }
  cout << "Num houses with santa and robot: " << houses.size() << endl;
}

int main() {
  char value;
  vector<char> inputs;
  while (cin >> value) {
    inputs.push_back(value);
  }
  part1(inputs);
  part2(inputs);
  return 0;
}
