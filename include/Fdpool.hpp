#ifndef FDPOOL_H
# define FDPOOL_H

class FDPool
{
private:
    int fd;
public:
    FDPool();
    virtual ~FDPool();
    void setFd(int fd);
    const int &getFd() const;
};

#endif