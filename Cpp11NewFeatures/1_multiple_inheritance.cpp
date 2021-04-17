#include <iostream>

class MusicalInstrument
{
public:
    MusicalInstrument() { std::cout << "Constructing Instrument" << std::endl; };
    virtual ~MusicalInstrument() { std::cout << "Destructing Instrument" << std::endl; };
    virtual void play() { std::cout << "Playing Instrument" << std::endl; }
    virtual void reset() { std::cout << "Reseting Instrument" << std::endl; }
};
class Machine
{
public:
    Machine() { std::cout << "Constructing Machine" << std::endl; };
    virtual ~Machine() { std::cout << "Destructing Machine" << std::endl; };
    virtual void start() { std::cout << "Starting Machine" << std::endl; }
    virtual void reset() { std::cout << "Reseting Machine" << std::endl; }
};
class Synthesizer : public Machine, public MusicalInstrument
{
public:
    Synthesizer() { std::cout << "Constructing Synthesizer" << std::endl; };
    virtual ~Synthesizer() { std::cout << "Destructing Synthesizer" << std::endl; };
};

int main()
{
    Synthesizer *pSynth = new Synthesizer();
    pSynth->play();
    pSynth->start();
    pSynth->MusicalInstrument::reset();
    pSynth->Machine::reset();
    delete pSynth;
    return 0;
}
