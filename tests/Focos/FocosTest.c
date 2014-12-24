#include "unity_fixture.h"
#include "Focos.h"

TEST_GROUP(Focos);

static uint16_t focos;

TEST_SETUP(Focos) {
    Focos_Crear(&focos);
}

TEST_TEAR_DOWN(Focos) { }

TEST(Focos, FocosApagadosDespuesDeCreacion) {
    uint16_t focos = 0xFFFF;
    Focos_Crear(&focos);
    TEST_ASSERT_EQUAL_HEX16(0, focos);
}

TEST(Focos, PrenderPrimerFoco) {
    Focos_Prender(1);
    TEST_ASSERT_EQUAL_HEX16(1, focos);
}

TEST(Focos, ApagarPrimerFoco) {
    Focos_Prender(1);
    Focos_Apagar(1);
    TEST_ASSERT_EQUAL_HEX16(0, focos);
}

TEST(Focos, PrenderVariosFocos) {
    Focos_Prender(9);
    Focos_Prender(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, focos);
}

TEST(Focos, ApagarCualquierFoco) {
    Focos_PrenderTodos();
    Focos_Apagar(8);
    TEST_ASSERT_EQUAL_HEX16(0xFF7F, focos);
}

TEST(Focos, PrenderTodos) {
    Focos_PrenderTodos();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, focos);
}

TEST(Focos, FocosNoSonDeLectura) {
    focos = 0xFFFF;
    Focos_Prender(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, focos);
}

TEST(Focos, NoGeneraDanoPrenderConFueraDeLimite) {
    Focos_Prender(-1);
    Focos_Prender(0);
    Focos_Prender(17);
    Focos_Prender(3141);
    TEST_ASSERT_EQUAL_HEX16(0, focos);
}

TEST(Focos, NoGeneraDanoApagarConFueraDeLimite) {
    Focos_PrenderTodos();
    Focos_Apagar(-1);
    Focos_Apagar(0);
    Focos_Apagar(17);
    Focos_Apagar(3141);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, focos);
}
