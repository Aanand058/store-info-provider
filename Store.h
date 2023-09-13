#ifndef SDDS_TG_H__
#define SDDS_TG_H__

#include <iostream>
using namespace std;

namespace sdds {

class Store {
  int storeNum;
  string status;

public:
  Store();
  Store(const int &num, const string &status);

  string retStatus() const;

  int retStoreNum() const;

  void display();
};

} // namespace sdds
#endif // !