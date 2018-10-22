// client.c
#include "square.h"

int main(int argc, char const *argv[])
{
	CLIENT *cl;
	square_in in;
	square_out *outp;

	//if(argc != 3) {
		//fprintf(stderr, "usage: client <hostname> <double_value>\n");
		//exit(0);
	//}
        
        //请注意，这里必须至少要有一个参数，就是server方的主机名
        if(argc != 2) {
                fprintf(stderr, "usage: client <hostname>\n");
                exit(0);
        }
	//cl = clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");
	//in.pass_in = atof(argv[2]);
	//if((outp = squareproc_1(&in, cl)) == NULL) { // 这里就是调用squareproc_1
		//fprintf(stderr, "%s\n", clnt_sperror(cl, argv[1]));
		//exit(0);
	//}

	//printf("result: %f\n", outp->return_out);
        cl = clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");
        outp = test_1(NULL,cl); //调用test_1函数，并且传递参数，因为在函数声明时参数类型为void *,因此在这里可以传递NULL作为第一个参数
        printf("result: %f\n", outp->return_out);
	return 0;
}
