#include <stdio.h>
#include <limits.h>
#include "bonus.h"

void test_int(char *desc, char *format, int nbr)
{
    int ret_orig;
    int ret_ft;

    printf("--- %s ---\n", desc);
    printf("Format: [%s] | Val: %d\n", format, nbr);

    // 1. Test printf originale
    printf("ORIG: |");
    ret_orig = printf(format, nbr);
    printf("|\n");

    // 2. Test tua ft_printf
    printf("FT  : |");
    fflush(stdout); // Svuota prima della tua write
    ret_ft = ft_printf(format, nbr);
    printf("|\n");

    // 3. Confronto dei return value
    if (ret_orig == ret_ft)
        printf("RET: OK (%d)\n", ret_ft);
    else
        printf("RET: KO! (Orig: %d | FT: %d)\n", ret_orig, ret_ft);
    printf("\n");
}

int main(void)
{
    printf("===== TEST COMPLETO INTERI (%%d / %%i) =====\n\n");
	
    // --- 1. SEGNI E SPAZI (FLAGS '+' e ' ') ---
    test_int("Default", "%d", 42);
    test_int("Flag +", "%+d", 42);
    test_int("Flag Spazio", "% d", 42);
    test_int("Flag + su negativo", "%+d", -42);
    test_int("Conflitto + e Spazio (vince +)", "% +d", 42);
    test_int("Conflitto + e Spazio (vince +)", "%+ d", 42);
    test_int("width < precision", "%10.50d", 42);
	
    // --- 2. WIDTH E ALLINEAMENTO (FLAG '-') ---
    test_int("Width 15", "%15d", 42);
    test_int("Width 10 Negativo", "%15d", -42);
    test_int("Minus 10 (Sinistra)", "%-10d", 42);
    test_int("Width < Numero", "%2d", 12345);

    // --- 3. PADDING ZERO (FLAG '0') ---
    test_int("Padding 0 (10 posizioni)", "%010d", 42);
    test_int("Padding 0 Negativo", "%010d", -42);
    test_int("Conflitto 0 e - (vince -)", "%0-10d", 42);

    // --- 4. PRECISIONE (IL PUNTO '.') ---
    test_int("Precisione 5", "%.5d", 42);
    test_int("Precisione 5 Negativo", "%.5d", -42); // Il '-' non conta nella precisione!
    test_int("Precisione 0 su valore 0 (NON STAMPA NULLA)", "%.0d", 0);
    test_int("Precisione 0 su valore 0 con Width", "%5.0d", 0); // Solo 5 spazi
    test_int("Precisione minore delle cifre", "%.2d", 12345);

    // --- 5. COMBINAZIONI COMPLESSE ---
    test_int("Width 10 e Precisione 5", "%10.5d", 42);
    test_int("Width 10, Precisione 5, Negativo", "%10.5d", -42);
    test_int("Width 10, Precisione 5, Flag +", "%+10.5d", 42);
    test_int("Conflitto 0 e Precisione (vince la precisione)", "%010.5d", 42);

    // --- 6. I CASI "DISTRUTTORI" (LIMITI) ---
    test_int("INT_MAX", "%d", INT_MAX);
    test_int("INT_MIN", "%d", INT_MIN); // L'incubo dell'overflow!
    test_int("INT_MIN con Width e Precisione", "%20.15d", INT_MIN);
    test_int("INT_MIN con Flag +", "%+d", INT_MIN);

    return (0);
}
