server: client server.cpp
	g++ server.o Socket.o -o server

client: client.o client.cpp
	g++ client.o Socket.o -o client

client.o:	server.o client.cpp
	g++ -c -g Socket.cpp client.cpp

server.o: Socket.o server.cpp
	g++ -c -g Socket.cpp server.cpp

Socket.o: Socket.cpp
	g++ -c -g Socket.cpp
