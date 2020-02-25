#include<iostream>
#include<vector>
#include<string>
class Player {
    private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp;}
    // default value for constructor, declaration 
    Player(std::string name_val="None", int health_val=10, int xp_val=3);
    // copy constructor
    Player(const Player &source);
    // destructor
    ~Player(){
        std::cout << "destructor for " << name << std::endl;
    };
};
// 3 args constructor 
Player::Player(std::string name_val, int health_val, int xp_val)
    :name {name_val}, health {health_val}, xp {xp_val}{
    std::cout << "3 arg constructor for " << name << std::endl;
}
// copy constructor
Player::Player(const Player &source)
// use initialization list:
//:name{source.name}, health{source.health}, xp {source.xp} {
// or use delegation:
:Player{source.name,source.health,source.xp} {
    std::cout << "copy constructor for " << source.name << std::endl;
}
// call by value, a copy of Player object will be passed into function
void display_player(Player p) {
    std::cout << "Name: " << p.get_name() << std::endl;
    std::cout << "Health: " << p.get_health() << std::endl;
    std::cout << "XP: " << p.get_xp() << std::endl;
}

int main() {
    Player empty;
    display_player(empty);
    
    //Player frank {"Frank"};
    //Player hero {"Hero", 100};
    Player villain {"Villain", 100};
    Player villain2 {villain};
    display_player(villain2);

    
    
    return 0;
}