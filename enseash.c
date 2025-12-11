#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define INPUT_BUFSIZE 128


const char welcome1[]="Bienvenue dans le Shell ENSEA.\n";
const char welcome2[]="Pour quitter, tapez 'exit'.\n";
const char prompt[]="enseash %";
const char exit_1[]="exit";

void printscript(const char *script){
    write(STDOUT_FILENO, script, strlen(script));
}
  
void enseash(void){
    char stock[INPUT_BUFSIZE];
    ssize_t nread;
    int status; 
    pid_t pid;

    printscript(welcome1);
    printscript(welcome2);

    while(1){
        printscript(prompt);        
        nread=read(STDOUT_FILENO, stock, INPUT_BUFSIZE-1);

        if (nread <= 0){
            // Stops the loop if reading input fails or reaches end of file
            printscript("Bye Bye...\n");
            break;
        } 
        
        stock[nread]='\0';
        if (stock[nread-1]=='\n'){
            stock[nread-1]='\0';
        }

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
        }

        if (strcmp(stock, exit_1)==0){
            // Exit command
            printscript("Bye Bye...\n");
            break;
        }
    }
}

int main(){
    enseash();
    return 0;
}
