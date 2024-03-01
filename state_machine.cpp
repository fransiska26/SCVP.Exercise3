#include <iostream>
#include <systemc.h>
#include "state_machine.h"

void stateMachine::process()
{   curPos++;
    switch(curState)
    {
        case Start:
            if (input.read() == inG) {
                curState = G;
            }
            else if (input.read() == inA || input.read() == inC || input.read() == inT ){
                curState = Start;
            }
        break;
        
        case G:
            if (input.read() == inA ){
                curState = GA;
            }
            else if (input.read() == inG) {
                curState = G;
            }
            else if (input.read() == inC || input.read() == inT) {
                curState = Start;
            }
        break;

        case GA:
            if (input.read() == inA ){
                curState = GAA;
            }
            else if (input.read() == inG) {
                curState = G;
            }            
            else if (input.read() == inC || input.read() == inT ){
                curState = Start;
            }            
        break;

        case GAA:
            if (input.read() == inG ){
                curState = GAAG;
            }
            // Answer for part 3 /GA{2,}+G/:
            else if (input.read() == inC || input.read() == inT ){
                curState = Start;
            }
            else if (input.read() == inA){
                curState = GAA;
            }

            // Answer for part 1 /GAAG/:
            // else if (input.read() == inA || input.read() == inC || input.read() == inT ){
            //     curState = Start;
            // }
        break;        
        
        case GAAG:
            counter++;
            cout << "counter: " << counter << "  position: " << curPos-4 << "-" << curPos << endl;            
            if (input.read() == inG ){
                curState = G;
            }
            else if (input.read() == inA || input.read() == inC || input.read() == inT ){
                curState = Start;
            }
        break;

        default:
            cout << "invalid input " << endl;
        break;
    }
}