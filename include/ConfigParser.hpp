#ifndef CONFIGPARSER_HPP
# define CONFIGPARSER_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <map>

class ConfigParser
{
private:
	bool finishWithSemiColon(std::string &token);
	bool startWithSlash(std::string &token);


public:
	ConfigParser();
	~ConfigParser(){};

	std::string fileToString(const std::string &file);
	std::string &EraseComment(std::string &target);
	std::vector<std::string> StringToToken(const std::string &src);
	int parselistenPort(std::vector<std::string>::iterator token_itr);
	std::string parseOnlyOneStringToken(std::vector<std::string>::iterator token_itr);
	void parseErrorPage(std::vector<std::string>::iterator token_itr, std::map<int, std::string> &error_page);
	std::string parseLocation(std::vector<std::string>::iterator token_itr);
	std::vector<std::string> parseIndexList(std::vector<std::string>::iterator token_itr);
	std::vector<std::string> parseAllow(std::vector<std::string>::iterator token_itr);

};

#endif