#include <stdio.h>

int sum(int *v, int v_size) {

    int sum = 0;
    for(int i=0; i<v_size; i++) {

        sum += *(v+i);
    }

    return sum;
}

void sortArray(int *v, int v_size) {

    for(int i=0; i<v_size; i++) {

        for(int j=i+1; j<v_size; j++) {

            if(v[i] > v[j]) {

                int inter = v[i];
                v[i] = v[j];
                v[j] = inter;
            }
        }
    }
}

int necessaryCondition(int *v, int v_size) {

    int v_sum = sum(v, v_size);
    for(int i=1; i<v_size/2 + 1; i++) {

        if((v_sum * i) % v_size == 0) {

            return 1;
        }
    }

    return 0;
}

int check(int index, int subarray_size, int subarray_sum, int *v, int v_size, int v_sum) {

    if(subarray_size != 0 && subarray_size != v_size && subarray_sum * v_size == v_sum * subarray_size) {

        return 1;
    }

    if(subarray_size > v_size/2) {

        return 0;
    }

    for(int i=index; i<v_size; i++) {
        
        if(i==index || v[i-1] != v[i]) {
            
            if(check(i + 1, subarray_size + 1, subarray_sum + v[i], v, v_size, v_sum)) {

                return 1;
            }
        }
    }

    return 0;
}

int main() {

    FILE *fin = fopen("./file.txt", "r");
    if(fin == NULL) {

        printf("error\n");
        printf("Could not open the input file!\n");
    }

    int v[30], v_size;
    fscanf(fin, "%d", &v_size);
    for(int i=0; i<v_size; i++) {

        fscanf(fin, "%d", v+i);
    }

    if(!necessaryCondition(v, v_size)) {

        printf("False\n");
    }

    sortArray(v, v_size);

    if(check(0, 0, 0, v, v_size, sum(v, v_size))) {

        printf("True\n");
    }
    else {
        
        printf("False\n");
    }
    
    return 0;
}