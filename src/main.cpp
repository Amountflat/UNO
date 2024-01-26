#include <iostream>
#include <uno.hpp>

using namespace amo::uno;

int main()
{
    Deck deck;

    std::cout << deck.GetOutput() << std::endl;

    deck.Init();

    std::cout << deck.GetOutput() << std::endl;

    return 0;
}
