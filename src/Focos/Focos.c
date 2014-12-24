#include "Focos.h"
#include "stdlib.h"
#include "memory.h"

enum {
    TODOS_PRENDIDOS = ~0,
    TODOS_APAGADOS = ~TODOS_PRENDIDOS
};

static uint16_t *focosDireccion;
static uint16_t focosImagen;

static uint16_t convertirABit(int numero) {
    return 1 << (numero - 1);
}

static void refrescarHardware(void) {
    *focosDireccion = focosImagen;
}

void Focos_Crear(uint16_t *focos) {
    focosDireccion = focos;
    focosImagen = TODOS_APAGADOS;
    refrescarHardware();
}

void Focos_PrenderTodos(void) {
    focosImagen = TODOS_PRENDIDOS;
    refrescarHardware();
}


void Focos_Prender(int paraFoco) {
    if (paraFoco <= 0 || paraFoco > 16)
        return;

    focosImagen |= convertirABit(paraFoco);
    refrescarHardware();
}

void Focos_Apagar(int paraFoco) {
    if (paraFoco <= 0 || paraFoco > 16)
        return;

    focosImagen &= ~(convertirABit(paraFoco));
    refrescarHardware();
}
