#ifndef LOCATION_HPP
# define LOCATION_HPP

# include <iostream>
# include <vector>

// 파싱 후 static한 값과 그렇지 않은 값이 있는가?
class Location
{
private:
	std::string root_dir;
	std::vector<std::string> index_list;
	std::vector<std::string> allow_method;
	std::string auth_message;
	std::string auth_file;
	bool auto_index;

public:
	Location();
	Location(const Location &from);
	~Location();
	Location	&operator=(const Location &rvalue);

	//test
	void showParseData();
};

#endif