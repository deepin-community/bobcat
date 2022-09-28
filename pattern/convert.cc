#include <iomanip>

#include "pattern.ih"

//namespace {
//    char const *s_state[] = 
//    {
//        "Start",
//        "Bs",
//        "Set",
//        "NegatedSet",
//        "SetBs",
//        "NestedSet",
//        "InsideASet",
//        "NegatedSetBs",
//        "NegatedNestedSet",
//        "InsideANegatedSet",
//    };
//}

void PerlSetFSA::convert(string &pattern)
{
    d_next = pattern.begin();

//cerr << "Pattern: " << pattern << '\n';

    d_target.clear();
    
    State state = Start;

    for (   ; d_next != pattern.end(); d_next++)
    {
        int  current = *d_next;

//cerr << "state: " << s_state[state] << ", input: " << current <<
//    " (" << static_cast<char>(current) << ") " <<
//    " from: " <<  (s_transition[state].first - s_stateTransitions) <<
//    ", to: "  <<  (s_transition[state].second - s_stateTransitions)
//    << '\n';

                                    // set the current char in the transition
                                    // matrix
        s_transition[state].second->d_input = current;    

        TransitionMatrix *mp = s_transition[state].first;
        while (mp->d_input != current)
            mp++;           // find the appropriate state transition element

//cerr << "next state: " << s_state[mp->d_next] << '\n';
        
        (this->*mp->d_action)();  // do the appropriate action
        
        state = mp->d_next;
//cerr << "target = " << d_target << "\n\n";

    }
    pattern = d_target;
}


