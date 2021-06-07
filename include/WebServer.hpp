#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include "FDPool.hpp"

class WebServer
{
private:
	FDPool fd_pool[FD_MAX];
	int open_fd_count;
public:
	bool isValidConfig(char *config_file);
	void initWith(char *config_file);
	void run();
};

#endif