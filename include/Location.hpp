#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <iostream>
# include <vector>

class Location
{
private:
    std::string root_dir;
    std::vector<std::string> index_list;
    std::vector<std::string> allow_method;
    
public:
    Location();
    Location(const Location &from);
    ~Location();
    Location	&operator=(const Location &rvalue);
};

#endif