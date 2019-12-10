#include "Socket.h"
int main(){
  string ip ="localhost";
  string port = "9876";
  string write;
  while(write!="exit"){
  std::cout << "Escriba el mensaje que quiere que se devuelva por el mirror server, solo se pasan 1024 bytes, escriba exit para salir"  << '\n';
  std::cin>>write;
  Socket *sock = new Socket(AF_INET,SOCK_STREAM,0); //AF_INET (Internet mode) SOCK_STREAM (TCP mode) 0 (Protocol any)
  string buffer;
  sock->connect(ip, port);
  //sock->socket_write("GET / HTTP/1.1\r\nhost: redes.ecci\r\n\r\n");
  sock->socket_write(write);

  sock->socket_read(buffer, 1024);
  cout << buffer << endl;
}
  return 0;
}
