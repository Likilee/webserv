#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP

class WebServer
{
private:
    /* data */
public:
    bool isValidConfig(char *config_file);
    void initWith(char *config_file);
    void run();
};

#endif