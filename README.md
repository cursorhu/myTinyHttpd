# myTinyhttpd

用web浏览器访问,httpd环境需要安装perl和perl-CGI  

1.CentOS上部署：
chmod +x *.sh  
./deploy.sh  

2.运行httpd  
./httpd  

3.打开浏览器，输入httpd所在的IP:port  
默认index.html返回color查询页面  
手动输入IP:port/date.html，返回date查询页面  

4.client可测试简单socket通信，不可和CGI同时使用，需重新编译和运行httpd  

编译方式：  
make clean && make test_sock=y  

后台运行httpd：  
./httpd & >/dev/null 2>&1  

运行测试程序:  
./client <httpd_ip> <httpd_port>  