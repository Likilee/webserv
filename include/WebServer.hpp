#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <map>
# include "FDPool.hpp"

class WebServer
{
private:
	std::map<int, FDPool> fd_pool; // fd_pool의 자료형은 무엇이 적합할까?
	int open_fd_count;
public:
	bool isValidConfig(char *config_file);
	void initWith(char *config_file);
	void run();

	//tester
	void showParseDataFd(int target_fd);
};

#endif