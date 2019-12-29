#include <iostream>
#include <string>
template<typename T>
T min(T a, T b) {return (a<b)? a:b;}

template<typename T1, typename T2>
void func(T1 a, T2 b) {std::cout << a << " " << b << std::endl; }

struct Player {
    std::string name;
    int age;
    bool operator<(const Player &rhs) const {return age < rhs.age;}};

std::ostream &operator<<(std::ostream &os, const Player &p) {os<<p.name;};

template <typename T>
void my_swap(T &a, T &b) {
    T temp {a};
    a = b;
    b = temp;}

int main () {
    std::cout << min(11.0,10.9) << std::endl;
    func(10, 10.9);
    
    Player p1 {"p1", 15};
    std::cout << p1.name << " " << p1.age << std::endl;
    Player p2 {"p2", 30};
    std::cout << p2.name << " " << p2.age << std::endl;
    Player p3 = min(p1,p2);
    std::cout << "p3: " << p3.name << " " << p3.age << std::endl;
    func(p1, p2);
    std::cout << "p1 name = " << p1.name << ", p2 name = " << p2.name << std::endl;
    my_swap(p1.name, p2.name);
    std::cout << "p1 name = " << p1.name << ", p2 name = " << p2.name << std::endl;
    std::cout << "p1 age = " << p1.age << ", p2 age = " << p2.age << std::endl;
    my_swap(p1.age, p2.age);
    std::cout << "p1 age = " << p1.age << ", p2 age = " << p2.age << std::endl;
    return 0;
}