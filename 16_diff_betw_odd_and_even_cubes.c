#include <stdio.h>
#include <math.h>

int main() {
    int n, f, i, c;
    double first, second, x_i, sum = 0;
    f = scanf("%d", &n);
    if (f == 1) {
        for (i = 1; i <= n; i++) {
            c = scanf("%lf", &x_i);
            if (c == 1)
            {
                first = pow(x_i, 3);
                second = pow(-1, (double) (i + 1));
                sum = sum + first * second;
            }
        }
        printf("%lf", sum);
    }
    return 0;
}
