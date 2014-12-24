#include "unity_fixture.h"

TEST_GROUP_RUNNER(Focos) {
    RUN_TEST_CASE(Focos, FocosApagadosDespuesDeCreacion);
    RUN_TEST_CASE(Focos, PrenderPrimerFoco);
    RUN_TEST_CASE(Focos, ApagarPrimerFoco);
    RUN_TEST_CASE(Focos, PrenderVariosFocos);
    RUN_TEST_CASE(Focos, ApagarCualquierFoco);
    RUN_TEST_CASE(Focos, PrenderTodos);
    RUN_TEST_CASE(Focos, FocosNoSonDeLectura);
    RUN_TEST_CASE(Focos, NoGeneraDanoPrenderConFueraDeLimite);
    RUN_TEST_CASE(Focos, NoGeneraDanoApagarConFueraDeLimite);
}
