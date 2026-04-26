#include <stdio.h>
#include <limits.h>
#include "bonus.h"

void test_p(char *title, char *format, void *p)
{
    int ret_std;
    int ret_ft;

    printf("--- Test: %s ---\n", title);
    // Usiamo %%p nel printf per stampare letteralmente "%p"
    printf("Format: [%s], Value: %p\n", format, p);

    // Test Originale
    printf("STD: [");
    fflush(stdout); // Svuota prima della printf standard
    ret_std = printf(format, p);
    fflush(stdout); // Svuota dopo per sicurezza
    printf("] -> return: %d\n", ret_std);

    // Test Tuo
    printf("FT : [");
    fflush(stdout); // Svuota PRIMA che ft_printf usi write
    ret_ft = ft_printf(format, p);
    // Non serve fflush dopo ft_printf perché write è immediata
    printf("] -> return: %d\n", ret_ft);

    if (ret_std == ret_ft)
        printf("\033[0;32mOK! ✅\033[0m\n\n");
    else
        printf("\033[0;31mDIFF! ❌\033[0m\n\n");
}

int main(void)
{
    int     a = 42;
    void    *ptr1 = &a;
    void    *ptr2 = (void *)LONG_MAX;
    void    *ptr3 = (void *)ULONG_MAX;

    printf("\033[1;35m--- INIZIO TEST %%p ---\033[0m\n\n");

    // 1. Caso Base
    test_p("Puntatore standard stack", "%p", ptr1);

    // 2. Il caso critico su Linux: NULL
    test_p("Puntatore NULL (Linux deve dare (nil))", "%p", NULL);

    // 3. Indirizzi estremi
    test_p("Puntatore LONG_MAX", "%p", ptr2);
    test_p("Puntatore ULONG_MAX (64-bit)", "%p", ptr3);
    test_p("Puntatore con valore 0", "%p", (void *)0);

    // 4. Width (Larghezza)
    test_p("Width 20", "%20p", ptr1);
    test_p("Width 20 con NULL", "%20p", NULL);

    // 5. Minus (Allineamento a sinistra)
    test_p("Minus flag %-20p", "%-20p", ptr1);
    test_p("Minus and zero flag %-020p", "%-020p", ptr1);
    test_p("Minus flag con NULL", "%-20p", NULL);

    // 6. Casi "strani" (La printf spesso ignora lo zero o la precisione su %p)
    test_p("Zero padding (spesso ignorato su %p)", "%020p", ptr1);
    test_p("Precisione (comportamento variabile)", "%.10p", ptr1);

    // 7. Mix di stringhe e puntatori
    printf("--- Test Multiplo ---\n");
    fflush(stdout);
    int r1 = printf("STD: Multi [%p] [%p] [%p]\n", ptr1, NULL, ptr3);
    fflush(stdout);
    int r2 = ft_printf("FT : Multi [%p] [%p] [%p]\n", ptr1, NULL, ptr3);
    printf("Return STD: %d | Return FT: %d\n", r1, r2);

    return (0);
}
