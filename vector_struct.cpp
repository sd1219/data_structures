#include<iostream>

using namespace std;

struct my_int_vector{
    int *elements;
    int count;
    int total_reads;
}

int size(my_int_vector *v){
    return v->count
}

void write(my_int_vector *v, int index, int value){
    if(index < 0 || v->count < index){
        cerr << "Error: index out of range." << endl;
        exit(1);
    }
    v->elements[index] = value;
}

int read(my_int_vector *v, int index){
    v->total_reads +=1;
    return v->elements[index];
}

int main(){
    return 0;
}