#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

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

    printscript(welcome1);
    printscript(welcome2);

    while(1){
        printscript(prompt);        
        nread=read(STDOUT_FILENO, stock, INPUT_BUFSIZE-1);

        if (nread <= 0){
            break;
        } // Stops the loop if reading input fails or reaches end of file
    }
}

int main(){
    enseash();
    return 0;
}
