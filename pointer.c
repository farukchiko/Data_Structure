#include <stdio.h>
//fungsi sum dari pointer
void sum(int *p){
    *p+=5;
}

int main(){
    int x,y;
    int *p; //pointer p

    x = 10; 
    y = 20;
    p = &x; //pointer p menunjuk ke alamat x

    x = x + 5;  
    y = *p + 10;    
    p = &y; 
    *p = x/2; //nilai y = x/2

    printf("x = %d\n", x);
    printf("y = %d\n", y);  
    printf("p = %d\n", *p); 

    //-------------------Case 3-------------------
    // int i = 10; 
    // int *p = &i;
    // int *q = p;

    // printf("p = %d\n", *p);

    // *q = 20;

    // printf("p = %d\n", *p);

    //-------------------Case 2-------------------
    // int x = 10;
    // int y = 20;

    // sum(&x);
    // sum(&y);

    // printf("nilai x = %d\n", x);
    // printf("nilai y = %d\n", y);

    //-------------------Case 1-------------------
    //int x = 5;
    //int *p = &x;
    //p adalah pointer yang menunjuk ke alamat x

    // printf("nilai awal x = %d\n", x);
    // printf("nilai pointer x ke p = %d\n", *p);

    // x = 10;

    // printf("nilai second x = %d\n", x);
    // printf("nilai pointer x ke p = %d\n", *p);

    // *p = 20;

    // printf("nilai third x = %d\n", x);
    // printf("nilai pointer x ke p = %d\n", *p);

    //jadi kita bisa mengubah nilai x dengan menggunakan pointer

    return 0;
}