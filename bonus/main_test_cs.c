
#include <limits.h>
#include "bonus.h"

// Helper per testare i caratteri
void test_c(char *desc, char *format, char c)
{
    int ret_orig, ret_ft;

    printf("--- %s ---\n", desc);
    printf("Format: [%s] | Char: '%c' (ASCII: %d)\n", format, c, c);
    
    printf("ORIG: |"); fflush(stdout);
    ret_orig = printf(format, c);
    printf("|\n");

    printf("FT  : |"); 
    fflush(stdout);
    ret_ft = ft_printf(format, c);
    printf("|\n");

    if (ret_orig == ret_ft)
        printf("RET: OK (%d)\n\n", ret_ft);
    else
        printf("RET: KO! (Orig: %d | FT: %d)\n\n", ret_orig, ret_ft);
}

// Helper per testare le stringhe
void test_s(char *desc, char *format, char *str)
{
    int ret_orig, ret_ft;

    printf("--- %s ---\n", desc);
    printf("Format: [%s] | Str: [%s]\n", format, str ? str : "NULL");
    
    printf("ORIG: |"); fflush(stdout);
    ret_orig = printf(format, str);
    printf("|\n");

    printf("FT  : |"); fflush(stdout);
    ret_ft = ft_printf(format, str);
    printf("|\n");

    if (ret_orig == ret_ft)
        printf("RET: OK (%d)\n\n", ret_ft);
    else
        printf("RET: KO! (Orig: %d | FT: %d)\n\n", ret_orig, ret_ft);
}

int main(void)
{
    printf("===== TEST CARATTERE (%%c) =====\n\n");
    test_c("Base", "%c", 'A');
    test_c("Spazio", "%c", ' ');
    test_c("Width", "%5c", 'B');
    test_c("Minus", "%-5c", 'C');
    
    // CASO CRITICO: Il carattere nullo
    test_c("Null byte (\\0)", "%c", '\0');
    test_c("Width + Null byte", "%5c", '\0');
    test_c("Minus + Null byte", "%-5c", '\0');

    printf("\n===== TEST STRINGA (%%s) =====\n\n");
    test_s("Base", "%s", "42 Napoli");
    test_s("Stringa Vuota", "%s", "");
    test_s("Width > Str", "%10s", "Ciao");
    test_s("Width < Str", "%3s", "Marmellata");
	test_s("Cruciani", "%5-s", "Marmellata");
	char *ciao = "Cruciani %5-s";
	printf(ciao, "Marmellata");
    
    // PRECISIONE
    test_s("Precisione < Str", "%.3s", "Marmellata");
    test_s("Precisione > Str", "%.10s", "Ciao");
    test_s("Precisione Zero", "%.0s", "Marmellata");
    
    // COMBINAZIONI
    test_s("Width + Precisione", "%10.4s", "Marmellata");
    test_s("Minus + Precisione", "%-10.4s", "Marmellata");

    // CASI BASTARDI: NULL (Comportamento Linux)
    test_s("NULL pointer", "%s", (char *)NULL);
    test_s("NULL con prec < 6", "%.3s", (char *)NULL);  // Deve stampare nulla
    test_s("NULL con prec >= 6", "%.6s", (char *)NULL); // Deve stampare (null)
    test_s("NULL con width e prec", "%10.8s", (char *)NULL);

    printf("\n===== TEST PERCENTUALE (%%%%) =====\n\n");
    int r1, r2;
    printf("ORIG: |%%|\n"); 
    r1 = printf("%%"); printf(" -> ret1: %d\n", r1);
    printf("FT  : |%%|\n"); 
    r2 = ft_printf("%%"); printf(" -> ret2: %d\n", r2);
    printf("ORIG: |stringa%%|\n"); 
    r1 = printf("stringa%%"); printf(" -> ret: %d\n", r1);
    printf("FT  : |stringa%%|\n"); 
    r2 = ft_printf("stringa%%"); printf(" -> ret: %d\n", r2);
    printf("ORIG: |stringa %% stringa|\n"); 
    r1 = printf("stringa %% stringa"); printf(" -> ret: %d\n", r1);
    r2 = ft_printf("stringa %% stringa"); printf(" -> ret: %d\n", r2);
	
    return (0);
}
