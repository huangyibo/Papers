// client.c
#include "square.h"

int main(int argc, char const *argv[])
{
	CLIENT *cl;
	square_in in;
	square_out *outp;

	if(argc != 3) {
		fprintf(stderr, "usage: client <hostname> <double_value>\n");
		exit(0);
	}

	cl = clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");
	in.pass_in = atof(argv[2]);
	if((outp = squareproc_1(&in, cl)) == NULL) { // 这里就是调用squareproc_1
		fprintf(stderr, "%s\n", clnt_sperror(cl, argv[1]));
		exit(0);
	}
	printf("result: %f\n", outp->return_out);

	return 0;
}
