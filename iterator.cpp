#include <iostream>


// using namespace std;
//
// int main(int argc, char const *argv[]) {
//   /* code */
//   std::vector<int> v = {1,3,4,7,8};
//
//   std::vector<int>::iterator i ;
//
//   //access elements std::vector<int> v; with iterator
//
//   for (i = v.begin(); i != v.end(); ++i){
//
//       *i = v[4];
//     cout << *i << endl;
//   }
//
//   return 0;
// }


//Building a custom iterable range like C++11 range

class nIterator {
  int i;
public:
  //initializer
  
  explicit nIterator(int position = 0) : i{position} {}

  int operator* () const {return i;}

  nIterator& operator++() {
    ++i;
    return *this;
  }

  bool operator != (const nIterator &other) const {
    return i != other.i;
  }
};

class nRange {
  int a;
  int b;

public:
  nRange (int from, int to) : a{from}, b{to} {}

  nIterator begin() const {return nIterator{a};}
  nIterator end() const {return nIterator{b};}
};

int  main(int argc, char const *argv[]) {
  /* code */
  std::string sNum;
  std::string sNum2;

        std::cout << "input two integers with the first lesser than the other" << '\n';
        std::getline(std::cin, sNum);
        std::cout <<"Here's the first number you entered - " << sNum << '\n';
        std::getline(std::cin, sNum2);
        std::cout << "Here's the second number you entered - " << sNum2 << '\n';

        int num = std::stoi(sNum);
        int num2 = std::stoi(sNum2);

      if (num < num2){
        nRange r {num, num2};
        std::cout << "Here's your iteration" << '\n';

        for (int i : r){
          std::cout << i << ", ";
        }
        std::cout << '\n';
      } else {
        nRange r {num2, num};
        std::cout << "Here's your iteration" << '\n';

        for (int i : r){
          std::cout << i << ", ";
        }
        std::cout << '\n';
      }
  return 0;
}
