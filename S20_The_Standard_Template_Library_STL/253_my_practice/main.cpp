#include<iostream>
#include<list>
#include<algorithm>
#include<iterator> // for std::advance
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);  
    std::string name;
    int age;
public:
    Person()
    : name {"Unknown"}, age {0} {}
    Person(std::string name, int age)
    : name{name}, age {age} {}
    bool operator<(const Person &r) const {
        return age < r.age;
    }
    bool operator==(const Person &r) const {
        return ((name == r.name) && (age == r.age));
    }
};
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ": " << p.age;
    return os;
}
template <typename T>
void display(const std::list<T> &l) {
    std::cout << "[";
    for (auto &i:l) {
        std::cout << i << " ";
    }    
    std::cout << "]" << std::endl;
}
void test1(){
    std::cout << "=====test1=====" << std::endl;
    std::list<int> l1 {1,2,3,4,5};
    display(l1);
    std::list<std::string> l2;
    l2.push_back("Back");
    l2.push_front("Front");
    display(l2);
    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10}; 
    display(l3);
    std::list<int> l4(10,100);
    display(l4);
}
void test2(){
    std::cout << "=====test2=====" << std::endl;
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);    
    std::cout << "Size: " << l.size() << std::endl;
    std::cout << "Front: " << l.front() << std::endl;
    std::cout << "Back: " << l.back() << std::endl;
    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}
void test3(){
    std::cout << "=====test3=====" << std::endl;
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};    
    display(l);
    l.resize(5);
    display(l);
    l.resize(10); // default initializer gives 0
    display(l);
    std::list<Person> person;
    person.resize(5); // use the Person default constructor
    display(person);
}
void test4(){
    std::cout << "=====test4=====" << std::endl;
    std::list<int> l {1,2,3,4,5,6,7,8,9,10};    
    display(l);
    auto it = std::find(l.begin(),l.end(),5);
    if (it != l.end())
        l.insert(it, 100);
    display(l);
    std::list<int> l2 {1000,2000,3000};
    l.insert(it,l2.begin(),l2.end()); // insert entire l2 
    display(l);
    std::advance(it, -4); // bi-directional iterator, point to the 100 
    std::cout << *it << std::endl;
    // remove the 100, iterator becomes invalid, don't use it again, if you need it, reset it
    l.erase(it); 
    display(l);
}
void test5(){
    std::cout << "=====test5=====" << std::endl;
    std::list<Person> stooges {
        {"Larru",18},
        {"Moe",25},
        {"Curly",17}
    };
    display(stooges);
    std::string name;
    int age {};
    std::cout << "Enter the name of next stooge:" << std::endl;
    getline(std::cin, name);
    std::cout << "Enter the age:";
    std::cin >> age;
    stooges.emplace_back(name,age);
    display(stooges);
    // insert frank before Moe
    auto it = std::find(stooges.begin(),stooges.end(),Person{"Moe",25}); // use overloaded == operator
    if (it != stooges.end())
        stooges.emplace(it,"Frank",18);
    display(stooges);
}
void test6(){
    std::cout << "=====test6=====" << std::endl;
    std::list<Person> stooges {
        {"Larru",18},
        {"Moe",25},
        {"Curly",17}
    };
    display(stooges);
    stooges.sort(); // use overloaded < operator
    display(stooges);
}
int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    return 0;
}
