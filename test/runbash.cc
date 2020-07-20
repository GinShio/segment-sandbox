#include "../include/sandbox.h"
using namespace std;
using namespace ssandbox;

char* container_args[] = {
	"/bin/bash",
	NULL
};

int func(void *args) {
	printf("Inside countainer [%05d]!\n", getpid());
	sethostname("container", 10);

	char **xargs = (char**)args;
	printf("+%s\n", xargs[0]);
	execv(xargs[0], xargs);
	printf("exiting\n");
}

int main(void) {
	sandbox_t cfg;
	cfg.function = func;
	cfg.func_args = container_args;
	cfg.stack_size = 1024 * 1024; // 1MB
	
	printf("Outside\n");
	create_sandbox(shared_ptr<sandbox_t>(&cfg));
	printf("Returned to father!\n");
	return 0;
}