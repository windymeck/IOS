#define COMMAND_SIZE 128
#define PATH_SIZE 500
#define ARG_SIZE 500

#define MSG_SIZE 500

#define FIFO_SHELL_SERVER "/tmp/FIFOSHELL_00"

#define REQUEST_RECEIVED              		1
#define STARTING_TO_SERVE_REQUEST   		2
#define REQUEST_SERVED		               	3

struct t_request
{
	char command[COMMAND_SIZE];  //for the command
	char location[PATH_SIZE];        //for the path
	char argument[ARG_SIZE];     //for the argument
	char answerBox[MSG_SIZE];    //name of the box to answer the client
};

struct t_answer
{
	int Type;				// REQUEST_RECEIVED, STARTING_TO_SERVE_REQUEST, REQUEST_SERVED
	char message[MSG_SIZE];      //the return message 
};
