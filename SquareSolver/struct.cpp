#include <cstdio>
#include <cmath>
#include <cstdlib>

#define MAX_COUNT 2
int count = 0;

struct myStruct {
    double items[MAX_COUNT];
    double item;
};
typedef struct myStruct st;

void createStruct (st *s) {
    s -> item = NAN;
}

void push(st *s, int pushItem) {
    if (count < MAX_COUNT) {
        s->items[count] = pushItem;
        count++;
    }
}

void printStruct (st *s) {
    for (int i = 0; i < count; i++) {
        printf("%lf\t", s->items[i]);
    }
}

int main() {
    st *s = (st*)malloc(sizeof(st));
    createStruct(s);
    push(s, 1.0);
    printStruct(s);
    printf("\n");
    push(s, 2.0);
    printStruct(s);
    printf("\n");
    free(s);
}
