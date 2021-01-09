#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int chld = 0;

void chld_handler(int sig) {
    std::cout << "recieved signal: " << sig << std::endl;
    exit(4);
}

void term_handler(int sig) {
    std::cout << "recieved sigterm: " << sig << std::endl;
    if (chld) {
        std::cout << "ending child process" << std::endl;
        kill(chld, SIGTERM);
    }
    exit(4);
}

int main() {
    signal(SIGCHLD, chld_handler);
    signal(SIGTERM, term_handler);
    int pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // child
        pid_t my_pid = getpid(); 
        for (;;) {
            std::cerr << "child pid: " << my_pid << ", child's parent = " << getppid() << std::endl;
            sleep(1);
        }
    } else {
        // parent
        pid_t my_pid = getpid(); 
        chld = pid;
        for (;;) {
            std::cerr << "parent pid: " << my_pid << std::endl;
            sleep(1);
        }
    }
}
