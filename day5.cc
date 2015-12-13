#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

bool contains(string& str, string key) {
  if (str.find(key) == string::npos) {
    return false;
  }
  return true;
}

int vowel_count(string& str) {
  int count = 0;
  count = count_if(begin(str), end(str), 
    [](char c) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
      return false;
    });
  return count;
}

bool contains_twice_in_a_row(string& str) {
  for (size_t i = 0; i < str.size() - 1; i++) {
    if (str.at(i) == str.at(i + 1)) {
      return true;
    }
  }
  return false;
}

bool contains_bad_pair(string& str) {
  if (contains(str, "ab")) return true;
  if (contains(str, "cd")) return true;
  if (contains(str, "pq")) return true;
  if (contains(str, "xy")) return true;
  return false;
}

int main() {
  string filename;
  cout << "Enter filename: " << endl;
  cin >> filename;
  ifstream file(filename);
  string line;
  int nice_count = 0;
  while (getline(file, line)) {
    if (vowel_count(line) >= 3 && contains_twice_in_a_row(line) && !contains_bad_pair(line)) {
      nice_count++;
    } 
  }
  cout << "Nice Count: " << nice_count << endl;
} 
