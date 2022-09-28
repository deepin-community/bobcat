#include "glob.ih"

//static
unordered_set<Glob::Type> Glob::fillSet(Type type)
{
    unordered_set<Type> ret;

    for (auto value: initializer_list<Type>{
                        BLOCK_DEVICE,
                        CHARACTER_DEVICE,   
                        DIRECTORY,
                        FIFO,
                        REGULAR_FILE,
                        SOCKET,
                        SYMBOLIC_LINK,
                    }
    )
    {
        if ((type & value) == value)
            ret.insert(value);
    }

    return ret;
}
