#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>

#define INPUT_BUFSIZE 128
#define _POSIX_C_SOURCE 199309L


const char welcome1[]="Bienvenue dans le Shell ENSEA.\n";
const char welcome2[]="Pour quitter, tapez 'exit'.\n";
const char exit_1[]="exit";

void printscript(const char *script){
    write(STDOUT_FILENO, script, strlen(script));
}

void update_prompt(char *dyn_prompt, int status, long elapsed_ms){
    if (WIFEXITED(status)){
        // Child exited normally, get exit code
        int code=WEXITSTATUS(status);
        snprintf(dyn_prompt, 64, "enseash [exit:%d|%ldms] %%", code, elapsed_ms);
    } 
    else if (WIFSIGNALED(status)){
        // Child killed by signal, get signal number
        int sig=WTERMSIG(status);
        snprintf(dyn_prompt, 64, "enseash [sign:%d|%ldms] %%", sig, elapsed_ms);
    } 
    else{
        // Basic prompt
        snprintf(dyn_prompt, 64, "enseash %%");
    }
}
  
void enseash(void){
    char stock[INPUT_BUFSIZE];
    char dyn_prompt[64]="enseash %";
    ssize_t nread;
    int status; 
    pid_t pid;
    struct timespec t_start, t_end;
    long elapsed_ms;

    printscript(welcome1);
    printscript(welcome2);

    while(1){
        printscript(dyn_prompt);        
        nread=read(STDIN_FILENO, stock, INPUT_BUFSIZE-1);

        if (nread <= 0){
            // Stops the loop if reading input fails or reaches end of file
            printscript("Bye Bye...\n");
            break;
        } 
        
        stock[nread]='\0';
        if (stock[nread-1]=='\n'){
            stock[nread-1]='\0';
        }
        
        if (strcmp(stock, exit_1)==0){
            // Exit command
            printscript("Bye Bye...\n");
            break;
        }

        clock_gettime(CLOCK_MONOTONIC, &t_start);
        pid=fork(); // Creation of the child

        if (pid==-1) {
            // Fork failed
            printscript("Erreur de fork\n");
        }
        else if (pid==0) {
            // Child tries to run the command (here fortune and date for instance)
            execlp(stock, stock, (char *)NULL);
            // If execlp returns, it failed
            printscript("Commande inconnue\n");
            exit(EXIT_FAILURE); // We kill the child process
        }
        else {
            // The father waits for the child to finish
            wait(&status); 
            clock_gettime(CLOCK_MONOTONIC, &t_end);
            elapsed_ms=(t_end.tv_sec-t_start.tv_sec)*1000+(t_end.tv_nsec-t_start.tv_nsec)/1000000;
            // Update prompt with last status
            update_prompt(dyn_prompt, status, elapsed_ms); 
        }
    }
}

int main(){
    enseash();
    return 0;
}
