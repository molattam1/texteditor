#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamicstack.h"
#include "custominput.h"


int main(void) {
    /* Program Entry */
    printf("Please enter command: ");
    char* input = read_line(stdin);
    if (input) {
        printf("You entered: %s\n", input);
        free(input);  // Don't forget to free!
    }

}
