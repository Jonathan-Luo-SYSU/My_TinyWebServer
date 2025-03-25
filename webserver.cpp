#include "webserver.h"

WebServer::WebServer()
{
    // 初始化服务器对象
}

WebServer::~WebServer()
{
    // 释放资源
}

void WebServer::init(int port , std::string user, std::string passWord, std::string databaseName,
            int log_write , int opt_linger, int trigmode, int sql_num,
            int thread_num, int close_log, int actor_model)
{
    m_port = port;
    m_user = user;
    m_passWord = passWord;
    m_databaseName = databaseName;
    m_sql_num = sql_num;
    m_thread_num = thread_num;
    m_log_write = log_write;
    m_OPT_LINGER = opt_linger;
    m_TRIGMode = trigmode;
    m_close_log = close_log;
    m_actormodel = actor_model;
}
void WebServer::event_process(){
    int m_listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(m_listenfd >= 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htons(INADDR_ANY);
    std::cout << m_port << std::endl;
    address.sin_port = htons(m_port);

    int ret;
    ret = bind(m_listenfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret >= 0);

    ret = listen(m_listenfd, 5);
    assert(ret >= 0);
    printf("Server started on port %d\n", m_port);

    while(true){
        int new_socket;
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);

        if ((new_socket = accept(m_listenfd, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
            perror("accept");
            close(m_listenfd);
            exit(EXIT_FAILURE);
        }

        // 读取数据
        char buffer[1024] = {0};
        int valread = read(new_socket, buffer, 1024);
        std::cout << "Received: " << buffer << std::endl;

        // 转换为大写字母
        for (int i = 0; i < valread; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] - 'a' + 'A';
            }
        }

        // 发送数据
        send(new_socket, buffer, valread, 0);
        std::cout << "Sent: " << buffer << std::endl;

        // 关闭连接
        close(new_socket);
    }

    close(m_listenfd);

}