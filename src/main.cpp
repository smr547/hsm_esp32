#include <Arduino.h>

#include "qpcpp.hpp"    // QP/C++ framework
#include "qhsmtst.hpp"  // QHsmTst state machine
#include "esp_sleep.h"

void setup() {
    Serial.begin(115200);
    APP::the_sm->init(0U);  // trigger the initial tran. in the test SM
    Serial.print("Waiting for input >>> ");
}

void loop() {
    char rc;

    if (Serial.available() > 0) {
        rc = Serial.read();
        Serial.print("Read character '");
        Serial.print(rc);
        Serial.println("'");

        QP::QSignal sig = 0U;
        if ('a' <= rc && rc <= 'i') {  // in range?
            sig = (QP::QSignal)(rc - 'a' + APP::A_SIG);
        } else if ('A' <= rc && rc <= 'I') {  // in range?
            sig = (QP::QSignal)(rc - 'A' + APP::A_SIG);
        } else if ((rc == 'x') || (rc == 'X')) {  // x or X?
            sig = APP::TERMINATE_SIG;  // terminate the interactive test

        } else if ((rc == 's') || (rc == 'S')) {  // deep sleep
            Serial.println("Sleeping");
            esp_deep_sleep_start();
            sig = APP::IGNORE_SIG;  // terminate the interactive test
        } else {
            sig = APP::IGNORE_SIG;
        }

        QP::QEvt const e(sig);
        APP::the_sm->dispatch(&e, 0U);  // dispatch the event
    }
}

//............................................................................
extern "C" Q_NORETURN Q_onError(char const *const file, int_t const line) {
    // FPRINTF_S(stderr, "Assertion failed in %s, line %d", file, line);
    Serial.println("Assertion failed");
    while (1) {
    }
}

namespace APP {
//............................................................................
void BSP_display(char const *msg) { Serial.println(msg); }
//............................................................................
void BSP_terminate(int16_t const result) {
    Serial.println("Bye Bye");
    while (1) {
    }
}

}  // namespace APP
