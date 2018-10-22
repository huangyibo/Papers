// server.c
#include "square.h"

square_out *squareproc_1_svc(square_in *inp, struct svc_req *rqstp)
{
	static square_out out;
	out.return_out = inp-> pass_in * inp->pass_in;

	return (&out);
}
