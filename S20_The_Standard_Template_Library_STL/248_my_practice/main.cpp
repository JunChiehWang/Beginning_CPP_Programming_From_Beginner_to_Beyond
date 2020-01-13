#include <iostream>
#include <array>
#include <algorithm>
#include <numeric> // for more algorithm like accumulate
// display the array -- the size must be included
// when passing a std::array to a function
void display(const std::array<int,5> &arr) {
    std::cout << "[";
    for (const auto &i:arr)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}
void test1(){
    std::cout << "=====test1=====" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5}; // double {{ }} if c++11
    std::array<int, 5> arr2; // we initialize array, but not elements of array  
    display(arr1);
    display(arr2); // elements are not initialized (contain garbage)
    arr2 = {10,20,30,40,50};
    display(arr1);
    display(arr2);
    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;
    arr1[0] = 1000; // no bound checking 
    arr1.at(1) = 2000; // bound checking
    display(arr1);
    std::cout << "front of arr2:" << arr2.front() << std::endl; // 10
    std::cout << "back of arr2:" << arr2.back() << std::endl; // 50
}
void test2(){
    std::cout << "=====test2=====" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5}; // double {{ }} if c++11
    std::array<int, 5> arr2 {10,20,30,40,50};
    display(arr1);
    display(arr2);
    arr1.fill(0);
    display(arr1);
    display(arr2);
    arr1.swap(arr2);    
    display(arr1);
    display(arr2);
}
void test3(){
    std::cout << "=====test3=====" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5}; // double {{ }} if c++11
    std::cout << arr1.data() << std::endl;  // return the address of 1st element of raw array   
    int *ptr = arr1.data();
    std::cout << ptr << std::endl;    
    std::cout << *ptr << std::endl;    
    *ptr = 100000;
    display(arr1);    
}
void test4(){
    std::cout << "=====test4=====" << std::endl;
    std::array<int, 5> arr1 {2,1,4,5,3}; // double {{ }} if c++11
    display(arr1);
    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}
void test5(){
    std::cout << "=====test5=====" << std::endl;
    std::array<int, 5> arr1 {2,1,4,5,3}; // double {{ }} if c++11
    std::array<int, 5>::iterator min_num = std::min_element(arr1.begin(),arr1.end());
    auto max_num = std::max_element(arr1.begin(),arr1.end());
    std::cout << "min: " << *min_num << ", max: " << *max_num << std::endl;
}
void test6(){
    std::cout << "=====test6=====" << std::endl;
    std::array<int, 5> arr1 {2,3,3,5,5}; // double {{ }} if c++11
    auto adjacent = std::adjacent_find(arr1.begin(),arr1.end()); // first occurrence of adjacent value 
    if (adjacent != arr1.end()) 
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else 
        std::cout << "No adjacent elements found" << std::endl;
}
void test7(){
    std::cout << "=====test7=====" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5}; // double {{ }} if c++11
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0); // from #include <accumulate>
    std::cout << "sum of the elements in arr1 is: " << sum << std::endl;
}
void test8(){
    std::cout << "=====test8=====" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};
    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3: " << count << " times" << std::endl;
}
void test9(){
    std::cout << "=====test9=====" << std::endl;
    std::array<int, 10> arr1 {1,2,3,50,60,70,80,200,300,400};
    // find how many times numbers are between 10 and 200 -> 50,60,70,80
    int count = std::count_if(arr1.begin(),arr1.end(),
                              [](int x){return x>10 && x<200;});
    std::cout << "Found " << count << " matches" << std::endl;
}
int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    test9();
    return 0;
}
