CC=gcc
objects_server=server.o square_svc.o square_xdr.o
objects_client=client.o square_clnt.o square_xdr.o
square=square.h square_clnt.c square_svc.c square_xdr.c

server client: $(objects_server) $(objects_client)
	gcc -o server $(objects_server)
	gcc -o client $(objects_client)

server.o: server.c square.h
	$(CC) -c server.c
square_svc.o: square.h square_svc.c square.h
	$(CC) -c square_svc.c
square_xdr.o: square_xdr.c square.h
	$(CC) -c square_xdr.c

client.o: client.c square.h
	$(CC) -c client.c
square_clnt.o: square.h square_clnt.c
	$(CC) -c square_clnt.c

$(square): square.x
	rpcgen -C square.x

.PHONY:clean
clean:
	rm -rf $(objects_server) $(objects_client) client server $(square)
