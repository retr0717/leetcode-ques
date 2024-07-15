#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
  int num[] = {2, 7, 11, 15 };
  int target = 9;

  std::unordered_map<int, int> numMap;
  std::vector<int> result;

  for (int i = 0; i < num.size(); i++)
  {
    int complement = target - num[i];

    std::cout << "Complment : " << numMap.find(complement)
              << " numMap end : " << numMap.end();
    if (numMap.find(complement) != numMap.end())
    {
      result.push_back(num[complement]);
      result.push_back(i);
      break;
    }
    numMap[num[i]] = i;
  }

  for(auto i : result)
  {
    std::cout<<i;
  }
}
