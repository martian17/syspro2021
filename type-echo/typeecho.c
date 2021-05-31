// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main(int argc, char *argv[]){
    // printf("%d\n", STDIN_FILENO);
    // printf("%d\n", STDOUT_FILENO);
    char buff[2];// 2 in case I want to printf
    while(1){
	read(0, buff, 1);
	// debug code
	// printf("[%s]", buff);
	write(1, buff, 1);
    }
    exit(0);
}
