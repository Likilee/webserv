#include "WebServer.hpp"
#include "ServerFD.hpp"
#include "libft.hpp"
#include <iostream>
#include <fcntl.h>

bool WebServer::isValidConfig(char *config_file)
{
	int fd;

	fd = open(config_file, O_RDONLY);
	if (fd == -1)
		return (false);


}

void WebServer::initWith(char *config_file)
{
	int config_fd;
	std::vector<std::string> config_token;
	config_fd = open(config_file, O_RDONLY);
}

void WebServer::run()
{

}

// FDPool fd_pool[FD_MAX];
// int open_fd_count;
//tester
void WebServer::showParseDataFd(int fd)
{
	ServerFD* server;

	for (int i = 0; i < OPEN_MAX; ++i)
	{
		server = dynamic_cast<ServerFD*>(&this->fd_pool[i]);
		if (server != NULL)
		{

		}
	}
}
