#include <iostream>

class Array {
  private:
    int* array;
    
  public:
    int length;

  Array() {
    length = 10;
    array = new int[length];
  }
  Array(int l) {
    length = l;
    array = new int[length];
  }

  void init(int value) {
    for (int i = 0; i < length; i++) {
      array[i] = value;
    }
  }

  void put(int value, int index) {
    array[index] = value;
  }

  void print() {
    for (int i = 0; i < length; i++) {
      std::cout << array[i] << std::endl;
    }
  }

  ~Array() {
    delete[] array;
  }
};


void test() {
  Array arr;
  arr.init(5);
  arr.print();
}

int main() {
  test();
  return 0;
}



