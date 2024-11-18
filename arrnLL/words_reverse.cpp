#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string reverseWords(std::string s) {
  std::istringstream iss(s);
  std::vector<std::string> words;
  std::string word;

  while (iss >> word) {
    std::cout << "word : " << word;
    words.push_back(word);
  }

  std::string reversed;
  for (auto it = words.rbegin(); it != words.rend(); ++it) {
    if (!reversed.empty()) {
      reversed += " ";
    }

    reversed += *it;
  }

  return reversed;
}
