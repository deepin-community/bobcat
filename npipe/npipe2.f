inline NPipe::NPipe(NPipe &&tmp)
:
    Pipe(std::move(tmp))
{}
