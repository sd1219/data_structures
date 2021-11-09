#include<iostream>

using namespace std;

struct my_int_vector{
    int *elements;
    int count;
    };

int size(my_int_vector *v){
    return v->count;
}

void write(my_int_vector *v, int index, int value){
    if(index < 0 || v->count < index){
        cerr << "Error: index out of range." << endl;
        exit(1);
    }
    v->elements[index] = value;
}

int read(my_int_vector *v, int index){
    return v->elements[index];
}

my_int_vector iota(int n){
    my_int_vector res = {new int[n], n};
    for (int i = 0; i < n; i++){
        write(&res, i, i);
    }
    return res;
}

void destroy(my_int_vector *v){
    delete []v->elements
    delete []v;
}

my_int_vector *create(int size){
    my_int_vector *res= new my_int_vector[1];
    res->elements = new int[size];
    res->count = size;
    return res;
}

int main(){
   return 0;
}