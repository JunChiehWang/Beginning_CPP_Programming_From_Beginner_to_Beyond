#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value)
    : name{name}, value{value} {}
    std::string get_name() const {return name;}
    T get_value() const {return value;}
};

int main () {
    Item<int> aa("aa", 10);
    std::cout << aa.get_name() << " " << aa.get_value() << std::endl;
    
    Item<double> bb("bb", 10.99);
    std::cout << bb.get_name() << " " << bb.get_value() << std::endl;

    Item<std::string> cc("cc", "one");
    std::cout << cc.get_name() << " " << cc.get_value() << std::endl;
    
    Item<Item<std::string>> dd("dd",{"ee", "ee-value"});
    std::cout << dd.get_name() << " " 
              << dd.get_value().get_name() << " " << dd.get_value().get_value() << std::endl;
    
    std::cout << "---------" << std::endl;
    std::vector<Item<double>> vec{};
    vec.push_back({"ff", 1.11});
    vec.push_back({"gg", 2.22});
    for (const auto &i:vec) {
        std::cout << i.get_name() << " " << i.get_value() << std::endl;
    }
    
    return 0;
}