#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void dup_fd(int infd, int outfd, int errfd)
{
	if (infd != STDIN_FILENO) {
		dup2(infd, STDIN_FILENO);
		if (infd != outfd)
			close(infd);
	}
	if (outfd != STDOUT_FILENO) {
		dup2(outfd, STDOUT_FILENO);
		if (outfd != errfd)
			close(outfd);
	}
	if (errfd != STDERR_FILENO) {
		dup2(errfd, STDERR_FILENO);
		close(errfd);
	}
}

int process(char **cmd, int infd, int outfd, int errfd, int block)
{
	int status = 0;
	pid_t pid;

	pid = fork();
	if (pid == 0) {
		dup_fd(infd, outfd, errfd);
		execvp(cmd[0], &cmd[0]);
		exit(1);
	} else if (pid < 0) {
        perror("fork");
		status = -1;
	}

    if (block) {
		if (waitpid(pid, &status, 0) != pid)
			perror("waitpid() failed");

		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}
	return status;
}
