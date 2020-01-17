// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (const auto &song:playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "Current song:" << std::endl;
    std::cout << current_song << std::endl;
    //play_current_song(current_song);
}

int main() {
    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    // default: iterator for first song 
    std::list<Song>::iterator current_song = playlist.begin();
    std::cout << " " << std::endl;
    display_playlist(playlist,*current_song); //deference the iterator
    
    char select {};
    do {
        display_menu();
        std::cin >> select;
        select = std::toupper(select);

        if (select == 'F') {
            std::cout << "Play First Song" << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        } else if (select == 'N') {
            std::cout << "Play Next Song" << std::endl;
            current_song++;
            if (current_song == playlist.end()){
                std::cout << "Wrapping to start of playlist" << std::endl;
                current_song = playlist.begin();
            } 
            play_current_song(*current_song);
        } else if (select == 'P') {
            std::cout << "Play Previous Song" << std::endl;
            if (current_song == playlist.begin()){
                std::cout << "Wrapping to end of playlist" << std::endl;
                current_song = playlist.end();
            }   
            current_song--;
            play_current_song(*current_song);
        } else if (select == 'A') {
            std::string song_name, song_artist;
            int song_rating;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Add and play a new Song at current location" << std::endl;
            //std::cin.ignore();
            std::cout << "Enter song name:";
            getline(std::cin,song_name);
            std::cout << "Enter song artist:";
            getline(std::cin,song_artist);
            std::cout << "Enter your rating (1-5):" ;
            std::cin >> song_rating;
            //Song new_song (song_name,song_artist,song_rating);
            playlist.insert(current_song,Song{song_name,song_artist,song_rating});
            current_song--;
            play_current_song(*current_song);
        } else if (select == 'L') {
            std::cout << "List the current playlist" << std::endl;
            display_playlist(playlist,*current_song);
        } else if (select == 'Q') {
            std::cout << "Quitting" << std::endl;
        } else {
            std::cout << "Illegal choice, try again...";
        }
    } while (select != 'Q');
    
    std::cout << " " << std::endl;
    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}