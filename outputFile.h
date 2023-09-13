#include "Store.h"
#include "Item.h"
#include "fstream"
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace sdds;

void OutputFile(const vector<Item> &items, const vector<Store> &stores) {
  std::string filename = "output.txt";
  std::ofstream outputFile(filename);

  if (!outputFile.is_open()) {
    std::cerr << "Unable to open the file: " << filename << std::endl;
    return;
  }

  // Header
  outputFile << std::left << std::setw(50) << "Item Name ";
  outputFile << std::right << std::setw(5) << "Store Number" << std::right
             << std::setw(25) << "Store Status" << std::endl;

  outputFile << "--------------------------------------------------------------"
                "-------------------------------------"
             << endl;

  // Display and write to the file
  for (const Item &item : items) {
    outputFile << std::left << std::setw(50) << item.retName();
    outputFile << std::right << std::setw(5) << item.retStoreNum();

    auto printStatus = [&outputFile](const std::string &status) {
      if (status.length() > 3) {
        outputFile << std::right << std::setw(35) << status;
      } else {
        outputFile << std::right << std::setw(35) << "N/A";
      }
    };

    // TG status print
    auto tgStore =
        std::find_if(stores.begin(), stores.end(), [&item](const Store &store) {
          return item.retStoreNum() == store.retStoreNum();
        });

    if (tgStore != stores.end()) {
      printStatus(tgStore->retStatus());
    } else {
      outputFile << std::right << std::setw(35) << "N/A";
    }

    outputFile << std::endl;

    for (int num : item.numbers) {
      outputFile << std::right << std::setw(55) << num;

      // Status Print
      auto numStore =
          std::find_if(stores.begin(), stores.end(), [num](const Store &store) {
            return num == store.retStoreNum();
          });

      if (numStore != stores.end()) {
        printStatus(numStore->retStatus());
      } else {
        outputFile << std::right << std::setw(35) << "N/A";
      }

      outputFile << std::endl;
    }

    outputFile
        << "--------------------------------------------------------------"
           "-------------------------------------"
        << endl;
    outputFile << std::endl;
  }
 

  // Close the file
  outputFile.close();
  std::cout << "Output has been written to " << filename << std::endl;
}
