#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <iostream>
#include <sys/socket.h>
#include <cassert>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

class WebServer{
    public:
        WebServer();
        ~WebServer();

        void event_process();

    private:
        int i;

};

#endif