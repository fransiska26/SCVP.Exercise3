#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <systemc.h>

// TODO
SC_MODULE(stateMachine)
{
    private:
    enum base {Start, G, GA, GAA, GAAG};
    void process();
    base curState = base::Start;
    const char inG = 'G';
    const char inA = 'A'; 
    const char inC = 'C';
    const char inT = 'T';
    int counter = 0;
    int curPos = 0;

    public:
    sc_in<char> input;
    sc_in<bool> clk;

    SC_CTOR (stateMachine): input("input"), clk("clk")
    {
        SC_METHOD (process);
        sensitive << clk.pos();
        dont_initialize();
    }
};
#endif // STATE_MACHINE_H


