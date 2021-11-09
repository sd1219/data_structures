#include<iostream>

using namespace std;

struct my_int_vector{
    int *elements;
    int count;
    int capacity;
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
    delete []v->elements;
    delete []v;
}

my_int_vector *create(int size){
    my_int_vector *res= new my_int_vector[1];
    res->elements = new int[size];
    res->count = size;
    return res;
}

void print(my_int_vector *vec){

    cout<<"<"<<vec->elements[0];
    for(int i = 1; i< vec->count; i++){
        cout<<", "<<vec->elements[i];
    }
    cout<<">"<<endl;
}

void resize(my_int_vector *vec, int new_size){
    my_int_vector *new_vec = create(new_size);
    for(int i = 0; i < vec->count; i++){
        new_vec->elements[i] = vec->elements[i];
    }
    for (int i = vec->count; i < new_size; i++){
        new_vec->elements[i] = 0;
    }
    vec->elements = new_vec->elements;
    vec-> count = new_vec->count;
    delete []new_vec;
}

void push_back(my_int_vector *vec, int v){
    
}



int main(){
    my_int_vector *vec = create(10);
    *vec = iota(5);
    print(vec);
    resize(vec, 3);
    print(vec);
    
    return 0;
}