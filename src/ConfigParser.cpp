#include "ConfigParser.hpp"
#include "libft.hpp"
#include "ErrorException.hpp"
#include <fcntl.h>
#include <string>
#include <fstream>
#include <streambuf>

ConfigParser::ConfigParser()
{
}

std::string ConfigParser::fileToString(const std::string &file)
{

	std::ifstream opened_file(file);
	std::string result((std::istreambuf_iterator<char>(opened_file)),
					std::istreambuf_iterator<char>());
	return (result);
}

std::string &ConfigParser::EraseComment(std::string &target)
{
	size_t start;
	size_t end;

	while (1)
	{
		start = target.find('#');
		if (start == std::string::npos)
			break ;
		end = target.find('\n', start);
		if (end == std::string::npos)
			end = target.size();
		target.erase(start, end - start);
	}
	return (target);
}

std::vector<std::string> ConfigParser::StringToToken(const std::string &src)
{
	std::vector<std::string> result;
	ft_split(src, " \t\n", result);
	return (result);
}

bool ConfigParser::finishWithSemiColon(std::string &token)
{
	if(token[token.length() - 1] == ';')
		return (true);
	return (false);
}

bool ConfigParser::startWithSlash(std::string &token)
{
	if (token[0] == '/')
		return (true);
	return (false);
}

int ConfigParser::parselistenPort(std::vector<std::string>::iterator token_itr)
{
	std::string token = *++token_itr;
	std::string error_message = "Config file have wrong token : " + token;

	if (false == finishWithSemiColon(token))
		throw(ErrorException(error_message.c_str()));
	for (size_t i = 0; i < token.length() - 1; ++i)
		if (false == ft_isdigit(token[i]))
			throw(ErrorException(error_message.c_str()));
	token.erase(token.length() - 1, 1);
	return (ft_atoi(token));
}

std::string ConfigParser::parseOnlyOneStringToken(std::vector<std::string>::iterator token_itr)
{
	std::string token = *++token_itr;
	std::string error_message = "Config file have wrong token : " + token;

	if (false == finishWithSemiColon(token))
		throw(ErrorException(error_message.c_str()));
	token.erase(token.length() - 1, 1);
	return (token);
}

void ConfigParser::parseErrorPage(std::vector<std::string>::iterator token_itr, std::map<int, std::string> &error_page)
{
	std::string token = *++token_itr;
	std::string error_message = "Config file have wrong token : " + token;
	std::vector<std::string>::iterator temp_itr = token_itr;

	if (finishWithSemiColon(token))
		throw(ErrorException(error_message.c_str()));
	while (false == startWithSlash(*temp_itr))
		++temp_itr;
	std::string error_page_path = *temp_itr;
	error_page_path.erase(error_page_path.length() - 1, 1);
	while (false == finishWithSemiColon(token))
	{
		for (size_t i = 0; i < token.length(); ++i)
			if (false == ft_isdigit(token[i]))
				throw(ErrorException(error_message.c_str()));
		error_page.insert(std::pair<int,std::string>(ft_atoi(token), error_page_path));
		token = *++token_itr;
	}
}

std::string ConfigParser::parseLocation(std::vector<std::string>::iterator token_itr)
{
	std::string token = *++token_itr;
	std::string error_message = "Config file have wrong token : " + token;

	if (false == startWithSlash(token))
		throw(ErrorException(error_message.c_str()));
	return (token);
}

