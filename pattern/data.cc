#include "pattern.ih"

//    Note: all state transitions MUST be clustered per state
//          the last element of a state cluster is the default transition.
//          its 0-value will be overwritten by the conversion.
//
//  PerlSetFSA::convert (convert.cc) converts the received regular expression
//  to a regcomp-compilable regex.

PerlSetFSA::TransitionMatrix PerlSetFSA::s_stateTransitions[] =
{
//   d_state            d_input d_next              d_action

    {Start,             '\\',   Bs,                 &PerlSetFSA::nop    },
    {Start,             '[',    Set,                &PerlSetFSA::copy   },
    {Start,             0,      Start,              &PerlSetFSA::copy   },
                                                    
    {Bs,                'd',    Start,              &PerlSetFSA::d_Set  },
    {Bs,                's',    Start,              &PerlSetFSA::s_Set  },
    {Bs,                'w',    Start,              &PerlSetFSA::w_Set  },
    {Bs,                'D',    Start,              &PerlSetFSA::D_Set  },
    {Bs,                'S',    Start,              &PerlSetFSA::S_Set  },
    {Bs,                'W',    Start,              &PerlSetFSA::W_Set  },
    {Bs,                0,      Start,              &PerlSetFSA::copybs },

    {Set,               '\\',   SetBs,              &PerlSetFSA::nop    },
    {Set,               0,      InsideASet,         &PerlSetFSA::copy   },

    {SetBs,             'd',    InsideASet,         &PerlSetFSA::d_Nest },
    {SetBs,             's',    InsideASet,         &PerlSetFSA::s_Nest },
    {SetBs,             'w',    InsideASet,         &PerlSetFSA::w_Nest },
    {SetBs,             '\\',   InsideASet,         &PerlSetFSA::copy   },
    {SetBs,             0,      InsideASet,         &PerlSetFSA::copybs },

    {InsideASet,        ']',    Start,              &PerlSetFSA::copy   },
    {InsideASet,        '\\',   SetBs,              &PerlSetFSA::nop    },
    {InsideASet,        0,      InsideASet,         &PerlSetFSA::copy   },
};

PerlSetFSA::TransitionMatrix *PerlSetFSA::s_stateTransitions_end = 
    PerlSetFSA::s_stateTransitions +
        sizeof(PerlSetFSA::s_stateTransitions) 
        / 
        sizeof(PerlSetFSA::TransitionMatrix);

vector<PerlSetFSA::statePair> PerlSetFSA::s_transition;

string Pattern::Regex::s_converted;
