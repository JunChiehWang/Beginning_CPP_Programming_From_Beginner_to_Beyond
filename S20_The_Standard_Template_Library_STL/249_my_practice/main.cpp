#include <iostream>
#include <vector>
#include <algorithm>
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p); 
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
    :name{name}, age{age} {}
    //when using our own class with STL, always always overload < and == operator, 
    //these are used by STL
    bool operator<(const Person &rhs) const {
        return age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return (name == rhs.name && age == rhs.age);
    }
};
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ": " << p.age;
} 
//use for_each and a lambda expression to display vector elements
//it has same effect as range for loop
void display2(const std::vector<int> &vec){
    std::cout << "[";
    std::for_each(vec.begin(),vec.end(),[](int x){std::cout << x << " ";});
    std::cout << "]" << std::endl;
}
//template function to display any vector
template <typename T>
void display(const std::vector<T> &vec){
    std::cout << "[";
    for (const auto &elem:vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}
void test1(){
    std::cout << "=====test1=====" << std::endl;
    std::vector<int> vec{1,2,3,4,5};
    display(vec);
    vec = {2,4,5,6}; // assignment using initialization list
    display2(vec);
    std::vector<int> vec1(10,100); // ten 100s in the vector using overloaded constructor
    display(vec1);
}
void test2(){
    std::cout << "=====test2=====" << std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;//number of element a vector can hold
    std::cout << "vec capacity: " << vec.capacity() << "\n" << std::endl;
    // if you exceed capacity the vector will increse its size
    // STL will allocate space for a larger vector (remember it's all contiguous in memory) 
    // and copy stuff into it.
    
    vec.push_back(6);
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << "\n" << std::endl;// now its 100
    // This is pretty typical, whenever you exceed the capacity, it'll double, So the next time the 
    // capacity will be 20 and then 40 and then 80 and so forth. Keep that in mind because if you've 
    // got 10,000 elements in here and you add 1, it's going to go to 20,000 when you only maybe need 
    // 10,000 and a little bit.
    
    vec.shrink_to_fit(); //C++ 11, it will shrink the amount of storage allocated to exactly the vector size.
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << "\n" << std::endl;
    
    vec.reserve(100); // now its 100, it won't expand until it hits 101 element.
    display(vec);
    std::cout << "vec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << "\n" << std::endl;
}
void test3(){
    std::cout << "=====test3=====" << std::endl;
    std::vector<int> vec {1,2,3,4,5};    
    display(vec);
    vec[0] = 100; // no bound checking
    vec.at(1) = 200;
    display(vec);
}
void test4(){
    std::cout << "=====test4=====" << std::endl;
    std::vector<Person> stooges;
    display(stooges);
    
    Person p1 {"Larry", 18};
    stooges.push_back(p1);
    display(stooges);
    
    //not creating a named object here so this is going to use move semantics
    stooges.push_back(Person{"Moe", 25});
    display(stooges);
    
    //use emplace_back, What we do here is we pass in the arguments the name and 
    //the age and what it's going to do behind the scenes is actually call the constructor 
    //for us and put curly at the back.
    stooges.emplace_back("Curly", 30);
    display(stooges);
}
void test5(){
    std::cout << "=====test5=====" << std::endl;
    std::vector<Person> stooges{
        {"Larry",18},
        {"Moe",25},
        {"curly",30}
    };   
    display(stooges);
    std::cout << "Front: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;
    stooges.pop_back();
    display(stooges);
}
void test6(){
    std::cout << "=====test6=====" << std::endl;
    std::vector<int> vec {1,2,3,4,5};  
    display(vec);
    
    vec.clear(); // remove all elements
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    vec.erase(vec.begin(), vec.begin()+2); // remove 1 and 2
    display(vec);

    vec = {1,2,3,4,5,6,7,8,9,10};
    // erase all even numbers
    auto it = vec.begin();
    while(it != vec.end()) {
        if (*it%2 == 0) {
            // Normally if we erase while iterating the vector we should reassign erase line to 
            // the iterator itself because of iter invalidation. Std::erase returns a new iterator 
            // that points next element right after the removed one.
            it = vec.erase(it);
        } else {
            it = it+1; // only increment if not erased ! 
        }
    }
    display(vec);
}
void test7(){
    std::cout << "=====test7=====" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};      
    std::vector<int> vec2 {10,20,30,40,50};      
    display(vec1);
    display(vec2);
    
    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}
void test8(){
    std::cout << "=====test8=====" << std::endl;
    std::vector<int> vec1 {1,21,3,40,12};
    display(vec1);
    std::sort(vec1.begin(),vec1.end());
    display(vec1);
}
void test9(){
    /* std::back_inserter construct a back-insert iterator that inserts new 
    elements at the end of the container it applied to. It's a special output 
    iterator, very efficient ! 
    Copy one list to another using an iterator and back_inserter
    */
    std::cout << "=====test9=====" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    display(vec1);
    display(vec2);
    // sequence = vec1.begin() ~ vec1.end(), 
    // each one of it is passed to the back of vec2
    std::copy(vec1.begin(),vec1.end(),std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    
    // copy_if the element is even
    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    display(vec1);
    display(vec2);
    // copy entire vec1 to vec2 using back_inserter if ....
    std::copy_if(vec1.begin(),vec1.end(),std::back_inserter(vec2),
                 [](int x){return x%2 ==0;});
    display(vec1);
    display(vec2);
}
void test10(){
    std::cout << "=====test10=====" << std::endl;
    // transform over 2 ranges
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3;
    // 1*10, 2*20, 3*30, 4*40, 5*50 and store result in vec3
    // start from begin of vec1 to end of vec1,
    // ref: https://www.fluentcpp.com/2017/02/13/transform-central-algorithm/
    std::transform(vec1.begin(),vec1.end(),vec2.begin(),
                   std::back_inserter(vec3),
                   [](int x, int y){return x*y;});
    display(vec1);
    display(vec2);
    display(vec3);
}
// insert vec2 into vec1 before the 5
void test11(){
    std::cout << "=====test11=====" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};
    display(vec1);
    display(vec2);
    auto it = std::find(vec1.begin(),vec1.end(),5); // find 5 in vec1
    if (it != vec1.end()){
        std::cout << "inserting.." << std::endl;
        vec1.insert(it,vec2.begin(),vec2.end()); // insert entire vec2 
    } else {
        std::cout << "Sorry, 5 not found" << std::endl;
    }
    display(vec1);
}
int main(){
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    //test9();
    //test10();
    test11();
    return 0;
}