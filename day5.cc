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

bool string_contains(string& str, vector<string>& keys) {
  for (auto& k : keys) {
    if (str.find(k) != string::npos) {
      return true;
    }
  }
  return false;
}

bool contains_bad_pair(string& str) {
  vector<string> bad_pairs = {"ab", "cd", "pq", "xy"};
  return string_contains(str, bad_pairs);
}

bool contains_nonoverlapping_pair(string& str) {
  for (size_t i = 0; i < str.size() - 2; i++) {
    string pattern = str.substr(i, 2);
    string remaining_str = str.substr(i + 2);
    if (contains(remaining_str, pattern)) {
      return true;
    }
  }
  return false;
}

bool contains_repeating_letter(string& str) {
  for (size_t i = 0; i < str.size() - 2; i++) {
    if (str.at(i) == str.at(i + 2)) {
      return true;
    }
  }
  return false;
}

int main() {
  string filename;
  cout << "Enter filename: ";
  cin >> filename;
  ifstream file(filename);
  string line;
  int p1_nice_count = 0;
  int p2_nice_count = 0;
  while (getline(file, line)) {
    if (vowel_count(line) >= 3 && contains_twice_in_a_row(line) && !contains_bad_pair(line)) {
      p1_nice_count++;
    } 
    if (contains_nonoverlapping_pair(line) && contains_repeating_letter(line)) {
      p2_nice_count++;
    } 
  }
  cout << "P1 nice count: " << p1_nice_count << endl;
  cout << "P2 nice count: " << p2_nice_count << endl;
} 
