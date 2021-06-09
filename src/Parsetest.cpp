#include "WebServer.hpp"
#include <iostream>
#include <fcntl.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		WebServer webserver;

		webserver.initWith(av[1]);

		int result = open("./result/parseTest", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		webserver.showParseDataFd(result);
	}
	else
	{
		std::cout << "Error : parseTest error - Invalid arguments" << std::endl;
	}
	return (0);
}