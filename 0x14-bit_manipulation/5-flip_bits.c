#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int count_set_bits(unsigned long int x) {
    unsigned int count = 0;
    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}
unsigned int flip_bits(unsigned long int n, unsigned long int m) {
    return count_set_bits(n ^ m);
}
