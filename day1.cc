#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<char> v;
  char value = '\0';
  while (cin >> value) {
    v.push_back(value);
  }
  auto floor_num = count(begin(v), end(v), '(') - count(begin(v), end(v), ')');
  cout << "Value: " << floor_num << endl;
  auto sum = 0;
  for (size_t i = 0; i < v.size(); i++) {
    if (v.at(i) == '(') {
      sum++;
    }
    else {
      sum--;
    }
    if (sum < 0) {
      cout << "Index is " << i << endl;
      break;
    }
  }
  return 0;
}
