#include <iostream>
#include <string>
/* we want: create an array class, of any size and any type (able to do 
Array<5> arr), create on the stack so compiler needs to know the size N 
(cannot pass it through a constructor) */
template <typename T, int N> // make it a template class, the user provide N at compile time
class Array {
    int size {N}; // how do we get the N ? => use template
    T values[N]; // N size of T types
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr) { // to display the array
        os << "[";
        for (const auto &val:arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val) {
        for (auto &item:values)
        item = init_val;
    }
    void fill(T val) {
        for (auto &item:values) 
        item = val;
    }
    int get_size() const {
        return size;
    }
    // overloaded subscript operator for ease use
    T &operator[](int index) {
        return values[index];
    }
};
int main() {
    Array<int, 5> nums; // expecting 2 items in <>
    std::cout << "the size of num is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;
    
    nums.fill(0);
    std::cout << nums << std::endl;
    
    nums[0] = 1000; // nums.operator[](0)
    std::cout << nums << std::endl;
    
    Array<int, 10> nums2 {1};
    std::cout << nums2 << std::endl;
    
    Array<std::string, 3> str1 {std::string {"Jerry"}};
    //str1.fill("_test_");
    std::cout << str1 << std::endl;  
    return 0;
}