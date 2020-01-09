#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype> // convert upper and lower case

class Person {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) 
    :name {name}, age {age} {}
    bool operator<(const Person &rhs) const {
        return (age < rhs.age);
    }
    bool operator==(const Person &rhs) const {
        return ((name == rhs.name) && (age == rhs.age));
    }
};

// find the element in a container
void find_test() {
    std::cout << "==========" << std::endl;
    std::vector<int> vec{1,2,3,4,5};
    //auto loc = std::find(vec.begin(), vec.end(), 1); or 
    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    if (loc != vec.end())
        std::cout << "Found the number" << std::endl;
    else
        std::cout << "couldn't find the number" << std::endl;
        
    std::list<Person> players{
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21},
    };
    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20}); // use == overloaded operator
    if (loc1 != players.end())
        std::cout << "Found Moe" << std::endl;
    else
        std::cout << "couldn't find Moe" << std::endl;
}

// count the number of elements in a container
void count_test() {
    std::cout << "==========" << std::endl;
    std::vector<int> vec {1,2,3,4,5,1,2,1};
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurences found" << std::endl;  
}

// count the number of occurences of an element in a container based on a 
// predicate using a lambda expression
void count_if_test() {
    std::cout << "==========" << std::endl;
    // count only if the element is even
    std::vector<int> vec {1,2,3,4,5,1,2,1,100};              
    int num = std::count_if(vec.begin(), vec.end(), [](int x){return x%2 == 0;}); // return true if x%2 == 0
    std::cout << num << " even numbers found" << std::endl;
    num = std::count_if(vec.begin(), vec.end(), [](int x){return x%2 != 0;}); // return true if x%2 != 0
    std::cout << num << " odd numbers found" << std::endl;
    num = std::count_if(vec.begin(), vec.end(), [](int x){return x>=5;}); // return true if element in vector >= 5
    std::cout << num << " numbers >= 5" << std::endl;
}

// replace occurrences of elements in a container
void replace_test() {
    std::cout << "==========" << std::endl;
    std::vector<int> vec {1,2,3,4,5,1,2,1};
    for (auto i:vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
        
    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i:vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void all_of_test(){
    std::cout << "==========" << std::endl;
    std::vector<int> vec {1,3,5,7,9,1,3,13,19,5};
    if ( std::all_of(vec.begin(), vec.end(), [](int x){return x>10;}) )
        std::cout << "All the elements are > 10" << std::endl;
    else
        std::cout << "Not all the elements are > 10" << std::endl;
        
    if ( std::all_of(vec.begin(), vec.end(), [](int x){return x<20;}) )
        std::cout << "All the elements are < 20" << std::endl;
    else
        std::cout << "Not all the elements are < 20" << std::endl;
}

// Transform elements in a container - string in this example
void string_transform_test() {
    std::cout << "==========" << std::endl;
    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); // ::____ it means global scope
    std::cout << "After transform: " << str1 << std::endl;
}

int main() {
    /*
    Person A {"A", 20};
    Person B {"B", 10};
    Person C {"A", 20};
    if (B < A) {std::cout << "B < A" << std::endl;}
    if (B == A) {std::cout << "B = A" << std::endl;}
    if (C == A) {std::cout << "C = A" << std::endl;}
    
    find_test();
    count_test();
    count_if_test();
    replace_test();
    all_of_test();
    */
    string_transform_test();
    
    return 0;
}

