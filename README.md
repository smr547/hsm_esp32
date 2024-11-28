# Heirarchical State Machine on ESP32

Demonstrate the use of a heirarchical state machine (HSM) on ESP32 by implementing the Example Heirarchical State Machine presented by
Miro Samek in [this video](https://www.youtube.com/watch?v=NxV7JlU0-F4) and also decribed in Chapter 2 of his book [Practical StateCharts in C/C++](https://www.state-machine.com/doc/PSiCC.pdf) 

The model for the state machine is contained in the [model file](./src/qhsmtst.qm) in the ``src`` directory. The free [QM tool from Quantum Leaps](https://www.state-machine.com/products/qm) must be used to generate the C++ code which implements the state machine.

## Installation

1. Clone this repository
2. Download the [QP bundle from Quantum Leaps](https://www.state-machine.com/#Downloads)
3. Generate the code for the HSM from the  [model file](./src/qhsmtst.qm) using the QM tool from [Quantum Leaps](https://www.state-machine.com/products/qm)
4. Use Platformio to build and test the code on an ESP32 dev module

Note the symbolic link in the ``src`` directory to the file ``~/qp/qpcpp/src/qf/qep_hsm.cpp`` is necessary to allow ``PlatformIO`` to correctly compile the HSM implementation code.

