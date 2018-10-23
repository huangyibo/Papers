server client: server.o square_svc.o square_xdr.o client.o square_clnt.o square_xdr.o
	gcc -o server server.o square_svc.o square_xdr.o
	gcc -o client client.o square_clnt.o square_xdr.o
server.o: server.c square.h
	gcc -c server.c
square_svc.o: square.h square_svc.c square.h
	gcc -c square_svc.c
square_xdr.o: square_xdr.c square.h
	gcc -c square_xdr.c
client.o: client.c square.h
	gcc -c client.c
square_clnt.o: square.h square_clnt.c
	gcc -c square_clnt.c

square.h square_clnt.c square_svc.c square_xdr.c: square.x
	rpcgen -C square.x
clean: 
	rm -rf *.o client server square.h square_clnt.c square_svc.c square_xdr.c
