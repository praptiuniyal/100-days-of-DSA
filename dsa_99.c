#include <stdio.h>
#include <stdlib.h>

// Structure for car
typedef struct {
    int pos;
    int speed;
} Car;

// Sort by position descending
int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;
    return c2->pos - c1->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &cars[i].pos);

    for(int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    // Sort cars by position (descending)
    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    float lastTime = -1;

    for(int i = 0; i < n; i++) {
        float time = (float)(target - cars[i].pos) / cars[i].speed;

        if(time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d", fleets);
    return 0;
}