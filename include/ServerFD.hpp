#ifndef SERVERFD_HPP
# define SERVERFD_HPP

# include <string>
# include <map>
# include "FDPool.hpp"
# include "Location.hpp"

class ServerFD : public FDPool
{
private:
	int port;
	std::string server_name;
	std::string access_log_path;
	std::string error_log_path;
	std::map<int, std::string> error_pages;
	std::map<std::string, Location> locations;
public:
	int	getPort();
	std::string getServerName();
	std::string getAccessLogPath();
	std::string getErrorLogPath();
	std::string getErrorPage(int status_code);
	Location &getLocation(const std::string &route);
	//test
	void showParseData();
};

#endif