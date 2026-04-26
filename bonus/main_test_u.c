#include "bonus.h"
#include <stdio.h>
#include <limits.h>

void test_u(char *title, char *format, unsigned int n)
{
    int ret_std;
	    int ret_ft;

    printf("--- Test: %s ---\n", title);
    printf("Format: [%s], Value: %u\n", format, n);
    
    // Test Originale
    printf("STD: [");
    ret_std = printf(format, n);
    printf("] -> return: %d\n", ret_std);

    // Test Tuo
    printf("FT : [");
    fflush(stdout);
    ret_ft = ft_printf(format, n);
    printf("] -> return: %d\n", ret_ft);
    if (ret_std == ret_ft)
        printf("\033[0;32mOK! ✅\033[0m\n\n");
    else
        printf("\033[0;31mDIFF! ❌\033[0m\n\n");
}

int main(void)
{
    printf("\033[1;35m--- INIZIO TEST %%u ---\033[0m\n\n");

    // 1. Casi Base
    test_u("Semplice", "%u", 42);
    test_u("Zero", "%u", 0);
    test_u("Max Unsigned", "%u", UINT_MAX);
    test_u("Overflow (da signed)", "%u", -1);

    // 2. Width (Larghezza)
    test_u("Width > cifre", "%10u", 123);
    test_u("Width < cifre", "%2u", 12345);

    // 3. Precisione
    test_u("Precisione > cifre", "%.5u", 42);
    test_u("Precisione < cifre", "%.2u", 12345);
    test_u("Il Caso Bastardo: Precisione 0 con valore 0", "%.0u", 0);
    test_u("Punto senza numero (precisione 0)", "%.u", 0);

    // 4. Flags Combinatate
    test_u("Minus (allineamento sinistra)", "%-10u", 42);
    test_u("Zero padding", "%010u", 42);
    test_u("Zero padding + Precisione (lo zero deve sparire)", "%010.5u", 42);
    test_u("Minus + Precisione", "%-10.5u", 42);

    // 5. Casi limite e Mix
    test_u("Tutto insieme", "%-15.10u", 12345);
    test_u("Width e Precisione uguali", "%5.5u", 123);

    printf("\033[1;35m--- FINE TEST ---\033[0m\n");
    return (0);
}
