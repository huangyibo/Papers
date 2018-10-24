/*参数结构体，参数用于向server端传送数据，或者接收server端返回的数据*/
struct square_in {
	double pass_in;
};

struct square_out {
	double return_out;
};


/*调用程序*/
program SQUARE_PROG {
        /*版本号，每个版本号后面都有一个=1或者=2这样形式的数字，*/
	version SQUARE_VERS {
                /*调用程序，类似于函数声明，并且rpc默认函数声明只能有一个参数，如果有多个参数，则使用结构体封装*/
		square_out SQUAREPROC(square_in) = 1;
                square_out test() = 2;
	} = 1;   
} = 0x31230000;
