#include "pattern.ih"

    // all subsequent elements of s_stateTransion[] are referrred to by
    // stateDescription
void PerlSetFSA::initialize(TransitionMatrix &stateDescription)
{
                                // statePtr points to the element matching 
                                // stateTransitions[]' element
    statePair *statePtr = &s_transition[stateDescription.d_state]; 

                                // not yet initialized: both point to the
    if (!statePtr->first)       // first element in stateTransitions[]
        *statePtr = statePair(&stateDescription, &stateDescription);
    else
       statePtr->second++;      // otherwise: there's another element: count
}                               // the #elements of a state

    // following th constructor's call s_transition holds #states elements,
    // each entry's first element points to the first line of that state in
    // s_stateTransitions[], the 2nd element points to the last line of
    // that state. E.g., for s_transition[1] first = &s_stateTransitions[3],
    // and first = &s_stateTransitions[9]
PerlSetFSA::PerlSetFSA()
{
    if (!s_transition.size())   // s_transition: vector of (#states) pairs
    {                           // of (initially 0-)pointers to
                                // s_stateTransition elements
        s_transition.resize(nStates_);  // initialize all elements to zeroes
        for (
            auto &transit:          // visit each s_stateTransitions element
            ranger(s_stateTransitions, s_stateTransitions_end)
        )
            initialize(transit);    
    }
}
