#include "webserver.h"

WebServer::WebServer()
{
    // 初始化服务器对象
}

WebServer::~WebServer()
{
    // 释放资源
}

void WebServer::event_process(){
    int m_listenfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(m_listenfd >= 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htons(INADDR_ANY);
    address.sin_port = htons(8080);

    int ret;
    ret = bind(m_listenfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret >= 0);

    ret = listen(m_listenfd, 5);
    assert(ret >= 0);
    printf("Server started on port 8080\n");

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