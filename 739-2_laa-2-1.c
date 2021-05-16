#include <stdio.h>

int main() {
    int n, c, f, count = 0, i;
    double x_i;
    c = scanf("%i", &n);
    if (c==1)
        for(i = 0; i < n; i++)
        {
            f = scanf("%lf", &x_i);
            if (f == 1)
                if(x_i > 0)
                    count++;
        }

    printf("%i", count);
    return 0;
}

