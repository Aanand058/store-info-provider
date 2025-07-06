# Store Info Provider

A C++ application that processes store information and item offers to generate comprehensive reports. This application reads data from two input files and produces a detailed output file showing store numbers, their statuses, and associated item offers.

## 🎯 Project Overview

The Store Info Provider is designed to:
- Read store information from `TG.txt` (store numbers and their current status)
- Read item offers from `item.txt` (items and their associated store numbers)
- Process and correlate this data
- Generate a comprehensive output file (`output.txt`) that displays store numbers, their conditions, and current statuses

## 📁 File Structure

```
store-info-provider/
├── main.cpp              # Main application logic
├── Store.h               # Store class header
├── Store.cpp             # Store class implementation
├── Item.h                # Item class header
├── Item.cpp              # Item class implementation
├── outputFile.h          # Output file processing header
├── outputFile.cpp        # Output file processing implementation
├── TG.txt                # Input file: Store numbers and statuses
├── item.txt              # Input file: Item offers and store numbers
├── output.txt            # Generated output file
└── README.md             # This file
```

## 🏗️ Architecture

The application follows Object-Oriented Programming principles with the following classes:

### Store Class
- **Purpose**: Represents store information
- **Properties**: 
  - `storeNum`: Store number
  - `status`: Current store status (e.g., "50 TG", "60 TG - Construction", "No Time Guarantee")
- **Methods**: Constructor, getters, and display functionality

### Item Class
- **Purpose**: Represents item offers
- **Properties**:
  - `itemName`: Name of the item/offer
  - `storeNum`: Associated store number
  - `numbers`: Vector of additional store numbers (for multi-store offers)
- **Methods**: Constructor, getters, and display functionality

### OutputFile Function
- **Purpose**: Processes and correlates store and item data
- **Functionality**: Generates formatted output showing item names, store numbers, and corresponding store statuses

## 📊 Data Format

### TG.txt (Store Information)
```
StoreNumber    Status
1              50 TG - Volume Store 286
3              50 TG
6              50 TG
...
```

### item.txt (Item Offers)
```
Item Name    StoreNumber
No Beer / Store offers Beer    158
No Classic Wings    408,56,423,33,67
...
```

### output.txt (Generated Report)
```
Item Name                                         Store Number             Store Status
---------------------------------------------------------------------------------------------------
No Beer / Store offers Beer                         158               60 TG - Construction
No Classic Wings                                    408                              50 TG
                                                    408                              50 TG
                                                     56                                N/A
...
```

## 🚀 Usage

### Prerequisites
- C++ compiler (GCC/G++ recommended)
- Input files: `TG.txt` and `item.txt`

### Compilation
```bash
g++ -o main.exe Item.cpp main.cpp Store.cpp outputFile.cpp
```

### Execution
```bash
./main.exe
```

### Expected Output
The application will generate an `output.txt` file containing the correlated store and item information.

## 🔧 Technical Details

- **Language**: C++
- **Paradigm**: Object-Oriented Programming
- **Namespace**: `sdds`
- **File I/O**: Uses `fstream` for file operations
- **Data Structures**: Vectors for dynamic storage
- **String Processing**: Manual parsing with `substr()` and `find()`

## 📋 Features

- **Data Correlation**: Matches item offers with store information
- **Multi-Store Support**: Handles items offered at multiple stores
- **Status Mapping**: Associates store numbers with their current operational status
- **Formatted Output**: Generates well-structured, readable reports
- **Error Handling**: Gracefully handles missing store information (shows "N/A")

## 🎯 Use Cases

This application is particularly useful for:
- **Retail Management**: Tracking store statuses and item availability
- **Inventory Planning**: Understanding which stores offer specific items
- **Operational Reporting**: Generating reports for store operations
- **Data Analysis**: Correlating store conditions with item offerings

## 🔍 Sample Output

The application processes data like:
- Store 158 offers "No Beer / Store offers Beer" and has status "60 TG - Construction"
- Store 408 offers "No Classic Wings" and has status "50 TG"
- Items offered at stores not in TG.txt show "N/A" for status

## 📝 Notes

- The application assumes tab-separated values in input files
- Store numbers must be integers
- The output file is overwritten on each execution
- Missing store information is handled gracefully with "N/A" status
