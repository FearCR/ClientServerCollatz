#include "Socket.h"
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>

double col(double x){
  double numero=x;
  if(fmod(numero,2)==0){
    numero=numero/2;
  }else{
    numero=(3*numero)+1;

  }
  return numero;
}
int main(){
  string ip = "localhost";
  string port = "9876";
  Socket *socket1 = new Socket(AF_INET,SOCK_STREAM,0);
  int optVal = 1;
  socket1->socket_set_opt(SOL_SOCKET, SO_REUSEADDR, &optVal);
  socket1->bind(ip, port);
  socket1->listen(10);
  std::cout<<"inicia el servidor"<<std::endl;
while(true){//este while se puede quitar y se quita el comentario de shutdown y close en socket 2
  while (true) {
    vector<Socket> lee(1);
    lee[0] = *socket1;
    int seconds = 10;
    if(Socket::select(&lee, NULL, NULL, seconds) < 1){
      //No hay coneccion
      continue;
    }else{
      //algo se recivio
      break;
    }
  }
  Socket *socket2 = socket1->accept();

  while (true) {
    vector<Socket> lee(1);
    lee[0] = *socket2;
    int seconds = 10;
    if(Socket::select(&lee, NULL, NULL, seconds) < 1){
      //No hay Input
      continue;
    }else{
      string buffer;
      socket2->socket_read(buffer, 1024);
      stringstream str(buffer);
      double numero=0;
      str>>numero;
      int pasos;
      std::cout<<"Numero: "<<numero<<std::endl;
      while(numero!=1){
      numero=col(numero);
      pasos++;
      std::cout<<"Numero: "<<numero<<std::endl;
  }
  buffer=std::to_string(pasos);
  string buffer2="Numero de pasos: "+buffer;
      socket2->socket_write(buffer2);
      pasos=0;
      break;
    }
  }
}
  //socket2->socket_shutdown(2);
  //socket2->close();

  socket1->socket_shutdown(2);
  socket1->close();


  return  0;
}
