#ifndef FILEDISCRIPTOR_HPP
# define FILEDISCRIPTOR_HPP

class FileDiscriptor
{
private:
    int fd;
public:
    FileDiscriptor();
    virtual ~FileDiscriptor();
    void setFd(int fd);
    const int &getFd() const;
};

#endif