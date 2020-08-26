#ifndef __APPLICATION_H__
#define __APPLICATION_H__

class Application
{
private:
    int m_port;
public:
    Application();
    int run(int argc, char **argv);
};

#endif