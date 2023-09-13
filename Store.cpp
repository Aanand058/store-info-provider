#define _CRT_SECURE_NO_WARNINGS
#include "Store.h"
#include <cstring>

using namespace std;

namespace sdds {

Store::Store() {}

Store::Store(const int &num, const string &status) {
  this->storeNum = num;
  this->status = status;
}

string Store::retStatus() const { return this->status; }

int Store::retStoreNum() const { return this->storeNum; }

void Store::display() {
  cout << this->storeNum << "       " << this->status << endl;
}
} // namespace sdds