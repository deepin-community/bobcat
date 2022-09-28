#ifndef INCLUDED_SPAWN_
#define INCLUDED_SPAWN_

#include <string>

#include <fstream>
#include <iostream>

#include <bobcat/fork>

#include <bobcat/pipe>
#include <bobcat/ifdbuf>
#include <bobcat/ofdbuf>
#include <bobcat/ifdstream>

class Spawn: public FBB::Fork, public std::ostream// , public std::istream
{
    FBB::Pipe d_insertPipe;
//    FBB::Pipe d_extractPipe;
//    FBB::Pipe d_errPipe;

    FBB::OFdBuf d_insertBuffer;
//    FBB::IFdBuf d_extractBuffer;
//    FBB::IFdStream d_errStream;

    std::string d_command;

    public:
        Spawn(std::string const &command);
    
        void end();

    private:
        void childProcess() override;
        void parentProcess() override;
        void childRedirections() override;
};
        
#endif





