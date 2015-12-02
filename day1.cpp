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
  return 0;
}