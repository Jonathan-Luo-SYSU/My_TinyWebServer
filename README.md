# My_TinyWebServer

## 启动步骤
服务器：
sh build.sh
./server

客户端：
nc localhost 9006

Step 1：
    实现简单的socket服务器与客户端通信，客户端发送小写字母，返回大写字母

Step 2：
    处理命令行参数

Step 3：
    划分 void eventListen() 与 void eventLoop() 函数