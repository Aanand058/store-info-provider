#define _CRT_SECURE_NO_WARNINGS

#include "Item.h"

using namespace std;

namespace sdds {
Item::Item(const string &str, const int &num) {
  this->itemName = str;
  this->storeNum = num;
}

string Item::retName() const { return this->itemName; }

int Item::retStoreNum() const { return this->storeNum; }

void Item::display() {

  std::cout << "Item: " << this->itemName
            << ", Store Number: " << this->storeNum << std::endl;
  for (int num : this->numbers) {
    std::cout << "Number: " << num << std::endl;
  }
  std::cout << std::endl;
}

} // namespace sdds