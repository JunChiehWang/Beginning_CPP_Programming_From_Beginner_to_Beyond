#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// display any vector of integers using range-based for loop
void display(const std::vector<int> &vec) {
    std::cout << "[";
    for (auto const &i:vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "===== test1 =====" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5}; 
    auto it = nums1.begin(); // point to 1
    std::cout << *it << std::endl;
    it++;                   // point to 2     
    std::cout << *it << std::endl;
    it = it + 2;            // point to 4 
    std::cout << *it << std::endl;
    it = nums1.end() - 1;   // point to 5 
    std::cout << *it << std::endl;    
}

void test2() {
    std::cout << "===== test2 =====" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};
    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }
    // change all vector element to 0
    it = nums1.begin();
    while(it != nums1.end()) {
        *it = 0;
        it++;
    }
    display(nums1);
}

// using a const iterator
void test3(){
    std::cout << "===== test3 =====" << std::endl;
    std::vector<int> nums1 {1,2,3,4,5};
    //std::vector<int>::const_iterator it1 = nums1.begin();
    //or 
    auto it1 = nums1.cbegin();
    
    while(it1 != nums1.end()){
        std::cout << *it1 << std::endl;
        it1++;
    }
    
    // compiler error when we try to change element
    it1 = nums1.begin();
    while(it1 != nums1.end()) {
        *it1 = 0; // compiler error, read only !
        it1++;
    }
}


int main() {
    //test1();
    //test2();
    //test3();
    return 0;
}