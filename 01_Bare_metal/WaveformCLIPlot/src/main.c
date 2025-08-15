#include <stdio.h>
#include "tasks.h"

int main(void) {
    printf("Hello\n");
    
    
    for(int i = 0; i<30;i++){
        task_plot_sine();
        task_plot_triangular();
        task_plot_square();
        printf("\n");
    }
    return 0;
}