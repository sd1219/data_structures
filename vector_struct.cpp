#include<iostream>

using namespace std;

struct my_int_vector{
    int *elements;
    int count;
    int capacity;
    };

int size(my_int_vector *v){
    return v->capacity;
}

void write(my_int_vector *v, int index, int value){
    if(index < 0 || v->capacity < index){
        cerr << "Error: index out of range." << endl;
        exit(1);
    }
    v->elements[index] = value;
}

int read(my_int_vector *v, int index){
    return v->elements[index];
}

my_int_vector *iota(my_int_vector*res, int n){
    //my_int_vector res = {new int[n], n};
    for (int i = 0; i < n; i++){
        write(res, i, i);
    }
    res->count = n;
    return res;
}

void destroy(my_int_vector *v){
    delete []v->elements;
    delete []v;
}

my_int_vector *create(int size){
    my_int_vector *res= new my_int_vector[1];
    res->elements = new int[size];
    res->capacity = size;
    return res;
}

void print(int n){ cout<< n<<endl;}

void print(my_int_vector *vec){

    cout<<"<"<<vec->elements[0];
    for(int i = 1; i< vec->capacity; i++){
        cout<<", "<<vec->elements[i];
    }
    cout<<">"<<endl;
    print(vec->count);
    print(vec->capacity);
}



void resize(my_int_vector *vec, int new_size){
    my_int_vector *new_vec = create(new_size);
    for(int i = 0; i < vec->capacity; i++){
        new_vec->elements[i] = vec->elements[i];
    }
    for (int i = vec->capacity; i < new_size; i++){
        new_vec->elements[i] = 0;
    }
    vec->elements = new_vec->elements;
    vec-> capacity = new_vec->capacity;
    delete []new_vec;
}

void push_back(my_int_vector *vec, int v){
    my_int_vector *new_vec;
    if(vec->count == vec->capacity){
        resize(vec,vec->capacity*2);
    }
    vec->elements[(vec->count)++] = v;    
    
}

void test(){
    my_int_vector *vec = create(10);
    print(vec);
    vec = iota(vec, 10);
    print(vec);
    write(vec, 3, 99);
    print(vec);
    push_back(vec, 11);
    print(vec);
}


int main(){
    test();

    return 0;
}