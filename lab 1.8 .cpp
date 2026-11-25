#include <stdio.h>


int dec_bit_by_one(int x) {
    unsigned int u = (unsigned int)x;
    unsigned int mask = 1u;

    while (mask != 0u) {
        int was_one = (u & mask) != 0u;
        u = u ^ mask;
        if (was_one) {
            break;
        }
        mask = mask << 1;
    }

    return (int)u;
}


int eq_bit(int a, int b) {
    int total_bits = (int)(sizeof(int) * 8);

    for (int bit = 0; bit < total_bits; bit++) {
        unsigned int mask = 1u << bit;
        int bit_a = ((unsigned int)a & mask) != 0u;
        int bit_b = ((unsigned int)b & mask) != 0u;
        if (bit_a != bit_b) {
            return 0;
        }
    }

    return 1;
}

int main(void) {

    int num = 61;


    if (num > 0)
    {
        printf("if: число %d додатне\n", num);
    }


    if (num % 2 == 0)
    {
        printf("if-else: число %d парне\n", num);
    }
    else
    {
        printf("if-else: число %d непарне\n", num);
    }


    int w_count = 0;
    while (w_count < 2)
    {
        w_count = w_count + 1;
    }
    printf("while-do: лічильник = %d\n", w_count);


    int d_count = 0;
    do
    {
        d_count = d_count + 1;
    } while (d_count < 2);
    printf("do-while: лічильник = %d\n", d_count);


    int f_sum = 0;
    for (int i = 1; i <= 3; i = i + 1)
    {
        f_sum = f_sum + i;
    }
    printf("for: сума 1..3 = %d\n\n", f_sum);

  


    int dec_vals[3] = {16, 61, -37};
    printf("=== Варіант 2: Лічильник зменшення на 1 ===\n");
    for (int i = 0; i < 3; i = i + 1)
    {
        int orig = dec_vals[i];
        int res = dec_bit_by_one(orig);
        printf("Операнд 1 = %d -> зменшення на 1 (бітово) = %d (перевірка: %d)\n",
               orig, res, orig - 1);
    }


    int op1[3] = {100, -8, 132};
    int op2[3] = {100, 125, 131};
    printf("\n=== Варіант 2: Операція відношення == ===\n");
    for (int i = 0; i < 3; i = i + 1)
    {
        int is_eq = eq_bit(op1[i], op2[i]);
        printf("Операнд 1 = %d, Операнд 2 = %d -> (==) результат: %d\n",
               op1[i], op2[i], is_eq);
    }

    return 0;
}
