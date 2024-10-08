#include "multibuf.ih"

void MultiBuf::insertStruct(stream &os, Insert &insert)
{
    switch (os.d_mode)
    {
        case ONCE:
            os.d_mode = RESET;
        [[fallthrough]];

        case ON:
            os.d_os->write(insert.buffer.data(),
                                                insert.buffer.size()).flush();
            insert.ok = insert.ok && os.d_os;
        break;

        default:
        break;
    }
}
