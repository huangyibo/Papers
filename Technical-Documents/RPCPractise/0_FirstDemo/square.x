struct square_in {
	double pass_in;
};

struct square_out {
	double return_out;
};

program SQUARE_PROG {
	version SQUARE_VERS {
		square_out SQUAREPROC(square_in) = 1;
	} = 1;
} = 0x31230000;
