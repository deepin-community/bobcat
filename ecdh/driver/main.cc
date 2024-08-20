#include "main.ih"

int main(int argc, char **argv)
try
{
    if (argc == 1)
    {
        usage(path{ argv[0] }.filename().string());
        return 0;
    }

    if ("curves"s == argv[1])           // show supported ECDH curves.
        cout << ECDH{};

    else if ("init"s == argv[1])        // initiator key construction
    {
                                        // write the file containing
                                        // the curve + public key
        ECDH ecdh{ ECDH::Initiator, "secp384r1", "init.pub" };

                                        // save the initiator's 
                                       // private key
        ecdh.privKey("init.sec", "use your passphrase");
            // not using encryption:
            // auto initSec = Exception::factory<ofstream>("init.sec");
            // initSec << ecdh.privKey() << '\n';
    }

    else if ("priv"s == argv[1])        // initiator key construction
    {
                                        // write the file containing
                                        // the curve + public key
        ECDH ecdh{ ECDH::Initiator, "secp384r1", "init.pub" };

        cout << "wait for the peer's public key. "
                "Press Enter to continue... ";
        cin.ignore(100, '\n');
                                                    // written to file
        auto initShared = Exception::factory<ofstream>("init.shared");
        initShared << ecdh.sharedKey("peer.pub") << '\n';  
    }

    else if ("peer"s == argv[1])        // peer's key construction
    {                                   
                                        // write the peer's public key
        ECDH ecdh{ ECDH::Peer, "init.pub", "peer.pub" }; 

                                        // save the peer's private
                                        // key (although not needed)
        auto out = Exception::factory<ofstream>("peer.sec");
        out << ecdh.privKey() << '\n';

        out = Exception::factory<ofstream>("peer.shared");
        out << ecdh.sharedKey() << '\n';
    }

    else if ("shared"s == argv[1])      // the initiator's shared key
    {                                   // construction
        ECDH ecdh{ "secp384r1", "peer.pub", "init.sec", 
                                            "use your passphrase" };

        auto initShared = Exception::factory<ofstream>("init.shared");
        initShared << ecdh.sharedKey() << '\n';     // written to file
    }
    
    else 
    {
        usage(path{ argv[0] }.filename().string());
        return 1;
    }
}
catch (exception const &exc)
{
    cerr << "Error: " << exc.what() << '\n';
    return 1;
}
catch (...)                     // and handle an unexpected exception
{
    cerr << "unexpected exception\n";
    return 1;
}
