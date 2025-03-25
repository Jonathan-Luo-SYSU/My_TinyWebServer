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

        void init(int port , std::string user, std::string passWord, std::string databaseName,
            int log_write , int opt_linger, int trigmode, int sql_num,
            int thread_num, int close_log, int actor_model);

        void eventListen();

        void eventLoop();


    public:
        // 基础
        int m_port;
        int m_close_log;
        int m_actor_model;
        int m_actormodel;

        // 数据库相关
        std::string m_user;
        std::string m_passWord;
        std::string m_databaseName;
        int m_sql_num;

        // 线程池相关
        int m_thread_num;

        // epoll_event相关
        int m_log_write;
        int m_OPT_LINGER;
        int m_TRIGMode;

        int m_listenfd;


    };

#endif