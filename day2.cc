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
  int paper_sum = 0;
  int ribbon_sum = 0;
  while (cin >> value) {
    ///////////////  CONVERT  ///////////////
    auto values = split(value, 'x');
    vector<int> nums;
    for (auto& v : values) {
      nums.push_back(stoi(v));
    }
    ///////////////  STORE  ///////////////
    sort(begin(nums), end(nums));
    int l = nums.at(0);
    int w = nums.at(1);
    int h = nums.at(2);
    ///////////////  PAPER  ///////////////
    paper_sum += 2*l*w + 2*w*h + 2*h*l;
    paper_sum =+ nums.at(0) * nums.at(1);
    ///////////////  RIBBON  ///////////////
    ribbon_sum += 2*nums.at(0) + 2*nums.at(1);
    ribbon_sum += l*w*h;
  }
  cout << "Surface area : " << paper_sum << endl;
  cout << "Ribbon length: " << ribbon_sum << endl;

  return 0;
}
