# FTP在线文件传输工具

**习宇兴**

FTP（File Transfer Protocol，文件传输协议） 是 TCP/IP 协议组中的协议之一，具有传输速度快的特点，用户可以利用客户端与服务器进行文件传输，实现上传下载。


## Server

	import socketserver
	import os
	import json

> *在python中，利用socketserver.ThreadingTCPServer函数可以很方便的实现多并发的文件传输，支持多个用户同时登录；
利用os模块实现文件路径的动态导入，增强代码可移植性；
利用json模块对字典类型进行序列化，方便传输大量指令。*

    access_addr = os.path.dirname(os.path.abspath(__file__))  # server\core
    DATABASE = {
        "volume": 5 * 1024 * 1024 * 1024,
        "used": 0
    }
    user_json = ''
    connect_num = 0

在MyTCPHandler类中定义类变量access_addr、DATABASE、user_json、connect_num对用户信息进行初始化，其中connect_num通过类名直接调用，实现静态变量的功能。

    def handle(self):
        MyTCPHandler.connect_num += 1
        print("%d Working..."% MyTCPHandler.connect_num)
        try:
            self.validate_logon()
            print(self.client_address[0])
            while True:
                msg = json.loads(self.request.recv(1024).decode())
                # self.access_addr = os.path.join(self.access_addr,'user_files',self.DATABASE["user name"])
                # server\user_files\
                cmd_str = 'cmd_' + msg["action"]
                if hasattr(self, cmd_str):
                    func = getattr(self, cmd_str)
                    func(msg)
        except ConnectionResetError as e:
            MyTCPHandler.connect_num -= 1
            print("%s客户端，断开连接"% self.client_address[0])

每当客户端连接服务器时，系统自动对MyTCPHandler类进行一次实例化，并且调用handle（）方法以实现与客户端的通信，我们可以在handle（）方法中执行相应操作；
通过self.request.recv(1024)接收客户端指令，利用反射将相应功能的函数赋值给func，通过调用func这一接口实现动态多态性；
利用try...except ConnectionResetError as e: 捕抓客户端断开造成的异常。
在MyTCPHandler类内，另设有如下方法：
    # 登录验证
    def validate_logon(self):
		...
		
	# 用户认证文件更新
    def up_json(self):
		...
		
	# 文件上传
    def cmd_put(self, msg_doc):
		...
		
	# 文件下载
    def cmd_get(self, msg_doc):
		...
	
	# 删除文件或目录
    def cmd_del(self, msg_doc):
		...
		
	# 查看容量
    def cmd_sp(self, msg_doc):
		...
		
	# 查看当前目录和目录下的内容
    def cmd_dir(self, *args):
		...
		
	# 切换目录
    def cmd_cd(self, msg_doc):
		...
		
	# 新建目录
    def cmd_mkdir(self, msg_doc):
		...
## Client
	import socket
	import os
	import json
	import sys
>客户端模块调用与服务器端类似

    def cmd_help(self, *args):
        msg = '''
            dir             #查看当前目录和目录下的内容
            sp              #查看容量
            cd ..\\..       #切换目录
            mkdir dirname   #新建目录
            get filename    #下载文件
            put filename    #上传文件
            del name        #删除文件或目录
        '''
        print(msg)
通过打印帮助文件，引导用户正确输入指令。

    def interative(self):
        self.authenticate()
        while True:
            cmd = input("请输入操作指令>>:").strip()
            if not len(cmd): continue
            cmd_str = 'cmd_' + cmd.split()[0]
            if hasattr(self, cmd_str):
                func = getattr(self, cmd_str)
                func(cmd)
            else:
                print("错误指令！")
                self.cmd_help()


def interative(self)入口函数中，与用户进行交互，再通过反射执行相应的功能。
另外在def cmd_get(self, *args)通过读取现存文件大小，与文件名一并发送给服务器，引导服务器将文件数据从上传断开处进行读取，实现文件的断点续传。


## 未实现的功能
>- MD5效验
- 用户交互界面

