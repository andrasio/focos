
#include "unity_fixture.h"
#include "stdio.h"
#include "string.h"

TEST_GROUP(FuncionesC);

static char salida[100];
static const char *esperado;


TEST_SETUP(FuncionesC) { 
    memset(salida, 0xAA, sizeof salida);
    esperado = "";
}

TEST_TEAR_DOWN(FuncionesC) { }

static void esperar(const char *s) {
    esperado = s;
}

static void dado(int caracteresEscritos) {
    TEST_ASSERT_EQUAL(strlen(esperado), caracteresEscritos);
    TEST_ASSERT_EQUAL_STRING(esperado, salida);
    TEST_ASSERT_BYTES_EQUAL(0xAA, salida[strlen(esperado) + 1]);
}

TEST(FuncionesC, SinFormato) {
    esperar("hola");
    dado(sprintf(salida, "hola"));
}

TEST(FuncionesC, FormatoCadena) {
    esperar("Hola mundo\n");
    dado(sprintf(salida, "Hola %s\n", "mundo"));
}
