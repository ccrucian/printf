#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "bonus.h" // Cambia con il tuo header

// Colori per una lettura rapida
#define G "\033[0;32m"
#define R "\033[0;31m"
#define B "\033[1m"
#define C "\033[0;36m"
#define RESET "\033[0m"

void test_hex(char *title, char *format, unsigned int n)
{
    int ret_std, ret_ft;

    printf(B C "--- %s ---\n" RESET, title);
    printf("Format: [%s], Value: %u (0x%x)\n", format, n, n);

    // Test STD
    printf("STD: [");
    fflush(stdout);
    ret_std = printf(format, n);
    fflush(stdout);
    printf("] -> ret: %d\n", ret_std);

    // Test FT
    printf("FT : [");
    fflush(stdout);
    ret_ft = ft_printf(format, n);
    // write non ha bisogno di fflush
    printf("] -> ret: %d\n", ret_ft);

    if (ret_std == ret_ft)
        printf(G "OK! ✅\n\n" RESET);
    else
        printf(R "DIFF! ❌\n\n" RESET);
}

int main(void)
{
    printf(B "\n=== TEST ESADECIMALI (%%x, %%X) ===\n\n" RESET);

    // --- 1. CASI BASE ---
    test_hex("Base minuscolo", "%x", 12345);
    test_hex("Base maiuscolo", "%X", 12345);
    test_hex("Zero standard", "%x", 0);
    test_hex("Valore massimo (UINT_MAX)", "%x", UINT_MAX);

    // --- 2. IL FLAG HASHTAG (#) ---
    // Ricorda: 0x compare solo se il valore NON è zero
    test_hex("Hashtag con valore", "%#x", 42);
    test_hex("Hashtag con valore 0 (Deve stampare solo '0')", "%#x", 0);
	test_hex("Hashtag con valore 0 e width", "%#10x", 0);
	test_hex("Hashtag con valore 42 e width", "%#10x", 42);
    test_hex("Hashtag maiuscolo", "%#X", 42);

    // --- 3. WIDTH E MINUS (- / width) ---
    test_hex("Width semplice", "%10x", 42);
    test_hex("Width + Hashtag", "%#10x", 42);
    test_hex("Minus (Left align)", "%-10x", 42);
    test_hex("Minus + Hashtag", "%-#10x", 42);

    // --- 4. PRECISIONE (.) ---
    // La precisione indica il numero MINIMO di cifre
    test_hex("Precisione semplice", "%.5x", 42);
    test_hex("Precisione < cifre reali", "%.2x", 1234);
    test_hex("Precisione + Hashtag", "%#.5x", 42);

    // --- 5. ZERO PADDING (0) ---
    test_hex("Zero padding", "%010x", 42);
    test_hex("Zero padding + Hashtag", "%#010x", 42);

    // --- 6. EVIL TESTS: GLI SCONTRI TRA FLAG ---
    
    // A. Se c'è la precisione, il flag '0' viene IGNORATO
    test_hex("EVIL: 0 flag vs Precisione", "%010.5x", 42);
    
    // B. Precisione 0 con valore 0 (Deve essere COMPLETAMENTE VUOTO)
    test_hex("EVIL: Valore 0, Precisione .0", "%.0x", 0);
    test_hex("EVIL: Valore 0, Precisione . (vuota)", "%.x", 0);
    
    // C. Width + Precisione 0 + Valore 0 (Deve stampare solo spazi)
    test_hex("EVIL: Width 5, Precisione .0, Valore 0", "%5.0x", 0);
    
    // D. Hashtag + Precisione 0 + Valore 0 (Niente 0x, niente 0)
    test_hex("EVIL: # + .0 + Valore 0", "%#.0x", 0);
    test_hex("EVIL: # + .5 + Valore 0", "%#.5x", 0);

    // E. Mix estremo
    test_hex("EVIL: Mix Minus, Hashtag, Width, Precision", "%-#15.10x", 0xabcdef);

    printf(B "=== FINE TEST ===\n" RESET);
    return (0);
}
