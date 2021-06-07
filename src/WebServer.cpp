#include "WebServer.hpp"
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

}

void WebServer::run()
{

}
