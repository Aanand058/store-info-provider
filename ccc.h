#ifndef SDDS_CCC_H__
#define SDDS_CCC_H__

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

namespace sdds {

class Item {
  string itemName;
  int storeNum;

public:
  // For offers in various stores
  std::vector<int> numbers;

  string retName() const;

  int retStoreNum() const;

  Item(const string &str, const int &num);

  void display();
};
} // namespace sdds
#endif // !