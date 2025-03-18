#include <stdio.h>

struct Node{
    int num;
};

struct Node ubah3(struct Node ***ptrd){ 
    (**ptrd)->num = 50; 
    return ***ptrd;
}

struct Node ubah2(struct Node **ptrt){
    //(**ptr).num = 90;
    (*ptrt)->num = 90; //jika ingin menggunakan ini harus mengurangi bintangnya untuk fungsinya tetap sama dengan yang diatas
    ubah3(&ptrt);
    return **ptrt;
}

struct Node ubah1(struct Node *ptr){
    (*ptr).num = 10;
    ubah2(&ptr);
    return *ptr; //fungsi ini mengembalikan nilai dari struct Node
}

int main(){
    struct Node n;
    n.num = 5;
    ubah1(&n);
    printf("%d", n.num);

    return 0;
}
