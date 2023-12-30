#include"HashTable.h"
int main() {

    std::ifstream inputFile("Text.txt");
    if (!inputFile.is_open()) {
        cout << "Mo file de ghi that bai\n";
        return 0;
    }
    else {
        cout << "Mo file de ghi thanh cong\n";
    }

    int m, insertCount, searchCount;
    string outputFileName;
    inputFile >> outputFileName;   //Read output fithPath
    inputFile >> m;                

    HashTable<int> hashtable(m, outputFileName.c_str());
    inputFile >> insertCount;

    // Inserst key
    for (int i = 0; i < insertCount; i++) {
        int key;
        inputFile >> key;
        hashtable.Insert(key);
    }

    // Search keys
    inputFile >> searchCount;
    for (int i = 0; i < searchCount; i++) {
        int key;
        inputFile >> key;
        hashtable.Search(key);
    }
    inputFile.close();


    return 0;
}



