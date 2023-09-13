#include "Store.h"
#include "Item.h"
#include "fstream"
#include "outputFile.h"
#include <algorithm>
#include <iomanip>

using namespace sdds;

int main() {
  ///////////////////// First Part ///////////////////////////////////////
  vector<Store> store1;
  ifstream file("TG.txt");

  int tgtempNum;
  string tempS = "Hello";
  string tgtempLine;

  while (getline(file, tgtempLine)) {
    tgtempNum = stoi(tgtempLine.substr(0, tgtempLine.find('\t')));
    tgtempLine.erase(0, tgtempLine.find(" ") + 1);
    tempS = tgtempLine;
    store1.emplace_back(tgtempNum, tempS);
  }

  ////////////////////////////// Second Part///////////

  std::ifstream inputFile("item.txt");

  vector<Item> newItem;
  std::string line;
  string tempLine;
  int tempNum;

  while (std::getline(inputFile, line)) {

    tempLine = line.substr(0, line.find('\t'));
    line.erase(0, line.find("\t") + 1);
    tempNum = stoi(line);

    newItem.emplace_back(tempLine, tempNum);

    std::istringstream iss(line);
    if (line.find(',') != std::string::npos) {

      int num;
      std::string token;
      int i = 0;

      while (std::getline(iss, token, ',')) {
        int num{0};
        std::istringstream numStream(token);
        numStream >> num;
        newItem.back().numbers.push_back(num);
        i++;
      }
    }
  }
  OutputFile(newItem, store1);

  /////////////////////////////// ccc.txt  END
  //////////////////////////////////////////////////////////////////
}
