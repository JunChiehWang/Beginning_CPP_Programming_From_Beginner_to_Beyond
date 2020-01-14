#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

//template function to display and deque
template <typename T>
void display(const std::deque<T> &d) {
    std::cout << "[";
    for (const auto &i:d)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}
void test1(){
    std::cout << "=====test1=====" << std::endl;
    std::deque<int> d {1,2,3,4,5};
    display(d);
    
    d = {2,4,5,6};
    display(d);
    
    std::deque<int> d1 (10,100); // ten 100s in the deque 
    display(d1);
    
    d[0] = 100;
    d.at(1) = 200;
    display(d);
}
void test2(){
    std::cout << "=====test2=====" << std::endl;
    std::deque<int> d {0,0,0};
    display(d);    
    d.push_back(10);
    d.push_back(20);
    display(d);    
    
    d.push_front(100);
    d.push_front(200);
    display(d);
    
    std::cout << "Front:" << d.front() << std::endl;
    std::cout << "Back:" << d.back() << std::endl;
    std::cout << "Size:" << d.size() << std::endl;
    
    d.pop_back();
    d.pop_front();
    display(d);
}
void test3(){
    // insert all even numbers into the back of a deque and all
    // odd numbers into the front 
    std::cout << "=====test3=====" << std::endl;
    std::deque<int> vec {1,2,3,4,5,6,7,8,9,10}; 
    std::deque<int> d;
    for (const auto &ele:vec) {
        if (ele%2 == 0)
            d.push_back(ele);
        else
            d.push_front(ele);
    }
    display(d);
}
void test4(){
    // push front vs push ordering
    std::cout << "=====test4=====" << std::endl;
    std::deque<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    for (const auto &ele:vec) {
        d.push_front(ele);
    }
    display(d);
    
    d.clear();
    
    for (const auto &ele:vec) {
        d.push_back(ele);
    }
    display(d);    
}
void test5(){
    // same as test4 using std::copy
    std::cout << "=====test5=====" << std::endl;    
    std::deque<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    std::copy(vec.begin(),vec.end(),std::front_inserter(d));
    display(d);
    
    d.clear();

    std::copy(vec.begin(),vec.end(),std::back_inserter(d));
    display(d);    
}
int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
    return 0;
}