#ifndef SDDS_OUTPUTFILE_H__
#define SDDS_OUTPUTFILE_H__

#include "Store.h"
#include "Item.h"
#include "fstream"
#include <algorithm>
#include <cstring>
#include <iomanip>

namespace sdds
{
  void OutputFile(const vector<Item> &items, const vector<Store> &stores);
}

#endif
