
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() 
{
  string aStr;
  string aRes;
  std::cout << "Print your string" << std::endl;
  getline(std::cin, aStr);
  if (aStr.empty())
  {
    std::cout << "String is empty" << std::endl;
    return 0;
  }
  for (int anId = 0; anId < aStr.length(); anId++) 
  {
    aStr[anId] = tolower(aStr[anId]);
  }

  std::map<char,int> aMap;
  for (int anId = 0; anId < aStr.length(); anId++) 
  {
    if (aMap.find(aStr[anId]) == aMap.end()) 
    {
      int aCount = 1;
      for (int i = anId + 1; i < aStr.length(); i++) {
        if (aStr[anId] == aStr[i]) {
          aCount++;
        }
      }
      aMap.insert(make_pair(aStr[anId], aCount));
    }
  }

  for (int anId = 0; anId < aStr.length(); anId++) 
  {
    if (aMap.find(aStr[anId])->second > 1)
    {
      aRes.push_back(')');
    } 
    else 
    {
      aRes.push_back('(');
    }
  }
  std::cout << "Converted string: " << aRes << std::endl;
  return 0;
}

