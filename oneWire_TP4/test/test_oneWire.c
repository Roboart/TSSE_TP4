/**
 * TEST TO DO:
 * 
 * INICIALIZAR EL DRIVER 1_WIRE
 * VERIFICAR SI HAY UN I-BUTTONS PRESENTE
 * ESCRIBIR UN BYTE
 * LEER UN BYTE
 * 
 **/

#include "unity.h"
#include "config.h"
#include "mock_onewire.h"
#include "OWire.h"

//#include <stdint.h>
//#include <stdlib.h>
//#include "stdio.h"


#define ONEWIRE_PIN 2
#define ONEWIRE_OK 1
#define ONEWIRE_FAIL 0

#define RES_INIT 3 // Un numero que este fuera de los valores de retorno de una funcion

onwire_t oneWire;
//uint8_t algo; 
void setUp(void)
{
    oneWire.onWire_PIN = ONEWIRE_PIN;
    oneWire.driverState = false;
    
}

//INICIALIZAR EL DRIVER 1_WIRE
void test_oneWire_init_OK(void){
    onwire_t oneWireTest;
    oneWireTest.onWire_PIN = ONEWIRE_OK;
    bool res = false;
    res = OW_init(&oneWireTest);
    TEST_ASSERT_TRUE(res);
}

//INICIALIZAR EL DRIVER 1_WIRE DE MANERA FALLIDA
void test_oneWire_init_Fail(void){
    onwire_t oneWireTest;
    oneWireTest.onWire_PIN = ONEWIRE_FAIL;
    bool res = false;
    res = OW_init(&oneWireTest);
    TEST_ASSERT_FALSE(res);
}


//VERIFICAR SI HAY UN I-BUTTONS PRESENTE
void test_oneWire_present(void){
    bool res = false;
    onewire_present_ExpectAndReturn(oneWire.onWire_PIN, true);
    res = OW_present(&oneWire);
    TEST_ASSERT_TRUE(res);
}

// ESCRIBIR UN BYTE
void test_oneWire_write_byte( void ){

    uint8_t res = RES_INIT;
    uint8_t valueToWrite = 0x33;

    //0X33 = 0011 0011
    onewire_write_bit_Expect(oneWire.onWire_PIN, true );  // 1
    onewire_write_bit_Expect(oneWire.onWire_PIN, true );  // 1
    onewire_write_bit_Expect(oneWire.onWire_PIN, false ); // 0
    onewire_write_bit_Expect(oneWire.onWire_PIN, false ); // 0
    onewire_write_bit_Expect(oneWire.onWire_PIN, true );  // 1
    onewire_write_bit_Expect(oneWire.onWire_PIN, true );  // 1
    onewire_write_bit_Expect(oneWire.onWire_PIN, false ); // 0
    onewire_write_bit_Expect(oneWire.onWire_PIN, false ); // 0
    
    OW_writeByte(&oneWire, valueToWrite);
}

//LEER UN BYTE
void test_oneWire_read_byte( void ){
    uint8_t res = 0x00;
    uint8_t res_Expected = 0x33;

    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, true );  // 1
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, true );  // 1
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, false ); // 0
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, false ); // 0
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, true );  // 1
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, true );  // 1
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, false ); // 0
    onewire_read_bit_ExpectAndReturn(oneWire.onWire_PIN, false ); // 0
    res = OW_readByte(&oneWire);


    TEST_ASSERT_EQUAL_INT8(res_Expected, res);

}
