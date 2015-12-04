#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

int main() {
  string value;
  int sum = 0;
  int ribbon_sum = 0;
  while (cin >> value) {
    auto values = split(value, 'x');
    vector<int> nums;
    for (auto& v : values) {
      nums.push_back(stoi(v));
    }
    int l = nums.at(0);
    int w = nums.at(1);
    int h = nums.at(2);
    auto surface_area = 2*l*w + 2*w*h + 2*h*l;
    sort(begin(nums), end(nums));
    for (auto& a : nums) {cout << a << " ";}cout << endl;
    auto smallest_side_area = nums.at(0) * nums.at(1);
    sum += surface_area + smallest_side_area;
    ///////////////  RIBBON  ///////////////
    ribbon_sum += 2*nums.at(0) + 2*nums.at(1);
    ribbon_sum += l*w*h;
  }
  cout << "Surface area : " << sum << endl;
  cout << "Ribbon length: " << ribbon_sum << endl;

  return 0;
}
