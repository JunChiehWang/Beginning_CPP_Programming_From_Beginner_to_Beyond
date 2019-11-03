#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Keeper {
    string name {"default_Keeper_name"};
    void set_name(string na) {name=na;};
    string get_name() {return name;};
};

class Player {
friend void display_player_2(Player &P);
private:
    string name;
    double age;
    int *data;
    static int num_players;
public:
    // cannot have a constant qualifier
    static int get_num_players(); 

    // getters with constant qualifier
    string get_name() const {return name;};
    double get_age() const {return age;};
    int get_data() const {return *data;};
    
    // setters
    void set_name(string na) {name = na;};
    void set_data(int d) {*data = d;};
    
    // delegating constructors + default constructor parameters
    Player(string na = "default", double ag = 0.0, int da=1);
    // copy constructor
    Player(const Player &source);
    // move constructor
    Player(Player &&source);
    // destructor
    ~Player();
};

// delegating constructors + constructor initialization list 
Player::Player(string na, double ag, int da)
:name {na}, age{ag} {
    data = new int;
    *data = da;
    cout << "3-arg constructor for : " << name << endl;
    ++num_players;
};

/*
// copy constructor (shallow)
Player::Player(const Player &source) 
:name {source.name}, age {source.age} // initialization list
{
    data = source.data; // shallow copy of pointer
    cout << "shallow copy constructor, make copy of :" << source.name << endl;
};*/

// copy constructor (deep)
Player::Player(const Player &source) 
:Player{source.name, source.age, *(source.data)} // delegating + deep copy
{
    //*data = *(source.data); // deep copy
    cout << "deep copy constructor, make copy of :" << source.name << endl;
};

// move constructor
Player::Player(Player &&source)
:name {source.name}, age {source.age}, data {source.data} 
{
    source.data = nullptr; // null original pointer
    cout << "move constructor, make move of :" << source.name << endl;
};

// get static number: num_players
int Player::get_num_players(){
    return num_players;    
};

// show player info using getter 
void display_player(const Player T) {
    cout << "in display_player, name = " << T.get_name() << endl;   
    cout << "in display_player, age = " << T.get_age() << endl;    
    cout << "in display_player, *data= " << T.get_data() << endl;
};

// dont need to use getter, it's a friend of Player
void display_player_2(Player &T) {
    cout << "display_player_2, name = " << T.name << endl;   
    cout << "display_player_2, age = " << T.age << endl;    
    cout << "display_player_2, *data= " << *(T.data) << endl;
};

// show active players
void display_active_players() { 
    cout << "active players: " << Player::get_num_players() << endl;
};

// destructor 
Player::~Player(){
    if (data != nullptr){
        cout << "destructor freeing data " << *data << " for " << name << endl;
    } else {
        cout << "destructor freeing data for nullptr for " << name << endl;
    }
    delete data;
    --num_players;
};

int Player::num_players = 0;

// main
int main()
{
    //display_active_players();
    
    //Player a;
    //display_player(a);
    
    //Player b{"b_1_arg"};
    //display_player(b);

    //Player *c = new Player{"c_2_arg", 20.0};
    //display_player(*c);
    //delete c;
    
    //Player new_b {b};
    //display_player(new_b);
    
    //Player d {"d_3_arg", 20.0, 2};
    //display_player(d);
    //Player e {d};
    //e.set_data(15);
    //cout << "e.get_data(): " << e.get_data() << endl;
    
    //vector<Player> vec;
    //vec.push_back(Player{"ff"}); // Player{"ff"} is r-values
    //vec.push_back(Player{"gg"}); // Player{"gg"} is r-values

    //const Player const_a {"constA", 18.5, 19};
    //display_player(const_a);
    //display_active_players();
    
    //Keeper h;
    //cout << h.name << endl;
    //h.set_name("h_new_name");
    //cout << h.get_name() << endl;
    
    Player i {"obj_j"};
    display_player(i);
    display_player_2(i);
    return 0;
}
