#include <stdio.h>

void ubah3(int ***ptrd){
    ***ptrd = 50;
}

void ubah2(int **ptrt){
    **ptrt = 40;
    ubah3(&ptrt);
}

void ubah1(int *ptr){
    *ptr = 10;
    ubah2(&ptr);
}

int main() {
    int num = 5;
    ubah1(&num);

    printf("%d", num);

    return 0;
}