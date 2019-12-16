// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    // print ruler + 1 blank line
    for (size_t i {1}; i <= 7; i++) {
        std::cout << "1234567890";  
    }
    std::cout << std::endl << std::endl;
    
    // print title + 1 blank line
    std::cout << std::setw(50) << tours.title << std::endl;
    std::cout << std::endl;
    
    // print title of country, city etc
    std::cout << std::setw(20) << std::left << "Country"
              << std::setw(25) << std::left << "City"
              << std::setw(10) << std::left << "Population"
              << std::setw(15) << std::right << "Price" << std::endl;
              
    // print dash line
    for (size_t i {1}; i <= 70; i++) {
        std::cout << '-';  
    }
    std::cout << std::endl;
    
    for(auto country : tours.countries) {   
        std::string ctr {country.name};
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(20) << std::left << ctr
                      << std::setw(25) << std::left << city.name 
                      << std::setw(10) << std::right << city.population 
                      << std::setw(15) << std::right << std::setprecision(2) << std::fixed << city.cost 
                      << std::endl;
            //std::string ctr {"   "};   not working this wayt !!! 
            ctr.erase();
        }

    }

    std::cout << std::endl << std::endl;
    return 0;
}