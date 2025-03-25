#include "config.h"
#include <string>
int main(int argc, char* argv[]) {

    //需要修改的数据库信息,登录名,密码,库名
    std::string user = "root";
    std::string passwd = "123456";
    std::string databasename = "tinywebserver";

    // 命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;

    // 初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
        config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
        config.close_log, config.actor_model);

    // webserver.event_process();

    //监听
    server.eventListen();

    //运行
    server.eventLoop();
    
    return 0;
}