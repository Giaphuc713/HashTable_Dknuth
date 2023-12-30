#include"HashTable.h"
template<class T>
HashTable<T>::HashTable(int m, const char* outputFileName) :size(m), outputFile(outputFileName)
{
    table = new Node * [size]();
    std::ofstream outputFileStream;
    outputFileStream.open(outputFile, std::ios::app);
    if (table != nullptr && outputFileStream.is_open()) {
        outputFileStream << "[constructor] - khoi tao thanh cong\n";
        outputFileStream << "+m = " << size << "\n";
        outputFileStream << "output file =" << outputFileName << "\n";
        outputFileStream.close();
    }
    else {
        if (outputFileStream.is_open()) {
            outputFileStream << "khoi tao that bai\n";
            outputFileStream.close();
        }
    }
}

template<class T>
void HashTable<T>::addTail(Node*& head, T key) {
    Node* newNode = new Node(key);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<class T>
T HashTable<T>::hashFunction(T key) {
    const double A = (sqrt(5) - 1) / 2;
    return static_cast<int>(size * fmod(key * A, 1));
}
  
template <class T>
  void HashTable<T>::Insert(T key) {
      int index = hashFunction(key);
      ++indexInsert;
      // Write result to output file
      std::ofstream outputFileStream;
      outputFileStream.open(outputFile, std::ios::app);
      if (outputFileStream.is_open()) {
          outputFileStream << "[insert " << indexInsert << "]" << "- thanh cong\n";
          outputFileStream << "+key =" << key << "\n";
          outputFileStream << "+hash value =" << index << "\n";
      }
      else {
          cout << "Error opening output file to insert" << std::endl;
      }
      // If the slot is empty, create a new node
      if (table[index] == nullptr) {
          table[index] = new Node(key);
          outputFileStream << "Xung dot =Khong\n";

      }
      else {
          // Collision occurred, add to the tail of the linked list
          addTail(table[index], key);
          outputFileStream << "Xung dot =Co\n";

      }
      outputFileStream.close();
  }

  template<class T>
  void HashTable<T>::Search(T key) {
      int index = hashFunction(key);
      Node* current = table[index];
      ++indexSearch;
      int checkChaning = 0;
      std::ofstream outputFileStream;
      // Search in the linked list
      while (current != nullptr) {
          if (current->key == key) {
              break;
          }
          else {
              current = current->next;
              checkChaning++;
          }

      }
      outputFileStream.open(outputFile, std::ios::app);
      if (outputFileStream.is_open() && current != nullptr) {
          outputFileStream << "[search " << indexSearch << "]" << "- tim thay\n";
          outputFileStream << "+ key =" << key << "\n";
          outputFileStream << "+ hash value = " << index << "\n";
          if (checkChaning == 0) { outputFileStream << "Xung dot = Khong\n"; }
          else { outputFileStream << "Xung dot = Co\n"; }
      }
      outputFileStream.close();

      // Key not found
      if (current == nullptr) {
          outputFileStream.open(outputFile, std::ios::app);
          outputFileStream << "[search " << indexSearch << "] - khong tim thay\n";
          outputFileStream << "+ key = " << key << "\n";
          outputFileStream << "+hash value= " << index << "\n";
          outputFileStream << "Xung dot = Khong\n";
          outputFileStream.close();
      }
  }
  
  template<class T>
  HashTable<T>::~HashTable() {
      int deleteCounter = 0;
      for (int i = 0; i < size; ++i) {
          Node* current = table[i];
          while (current != nullptr) {
              Node* next = current->next;
              if (next != nullptr) {
                  ++deleteCounter;
              }
              delete current;
              current = next;
          }
      }
      delete[] table;
      table = nullptr;
      std::ofstream outputFileStream;
      outputFileStream.open(outputFile, std::ios::app);
      outputFileStream << "[destructor] - huy bo thanh cong\n";
      outputFileStream << "+ so phan tu xung dot da delete = " << deleteCounter << "\n";
      outputFileStream << "+ da delete bang T\n";
      outputFileStream.close();
  }
  template class HashTable<int>;

