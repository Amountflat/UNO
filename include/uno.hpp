#pragma once

#include <string>

namespace amo{
    namespace uno{
        enum CardKind{
            // Numbers
            CKNUMBER = 0x000f,
            CKZERO   = 0x0001,
            CKONE    = 0x0002,
            CKTWO    = 0x0003,
            CKTHREE  = 0x0004,
            CKFOUR   = 0x0005,
            CKFIVE   = 0x0006,
            CKSIX    = 0x0007,
            CKSEVEN  = 0x0008,
            CKEIGHT  = 0x0009,
            CKNINE   = 0x000a,

            // Symbols
            CKSYMBOL    = 0x00f0,
            CKSKIP      = 0x0010,
            CKDRAW2     = 0x0020,
            CKREVERSE   = 0x0030,
            CKWILD      = 0x0040,
            CKWILDDRAW4 = 0x0050,

            // Colors
            CKCOLOR  = 0x0f00,
            CKRED    = 0x0100,
            CKBLUE   = 0x0200,
            CKGREEN  = 0x0300,
            CKYELLOW = 0x0400,

            // Reds
            CK_RED_0 = CKRED | CKZERO,
            CK_RED_1 = CKRED | CKONE,
            CK_RED_2 = CKRED | CKTWO,
            CK_RED_3 = CKRED | CKTHREE,
            CK_RED_4 = CKRED | CKFOUR,
            CK_RED_5 = CKRED | CKFIVE,
            CK_RED_6 = CKRED | CKSIX,
            CK_RED_7 = CKRED | CKSEVEN,
            CK_RED_8 = CKRED | CKEIGHT,
            CK_RED_9 = CKRED | CKNINE,

            // Blues
            CK_BLUE_0 = CKBLUE | CKZERO,
            CK_BLUE_1 = CKBLUE | CKONE,
            CK_BLUE_2 = CKBLUE | CKTWO,
            CK_BLUE_3 = CKBLUE | CKTHREE,
            CK_BLUE_4 = CKBLUE | CKFOUR,
            CK_BLUE_5 = CKBLUE | CKFIVE,
            CK_BLUE_6 = CKBLUE | CKSIX,
            CK_BLUE_7 = CKBLUE | CKSEVEN,
            CK_BLUE_8 = CKBLUE | CKEIGHT,
            CK_BLUE_9 = CKBLUE | CKNINE,

            // Greens
            CK_GREEN_0 = CKGREEN | CKZERO,
            CK_GREEN_1 = CKGREEN | CKONE,
            CK_GREEN_2 = CKGREEN | CKTWO,
            CK_GREEN_3 = CKGREEN | CKTHREE,
            CK_GREEN_4 = CKGREEN | CKFOUR,
            CK_GREEN_5 = CKGREEN | CKFIVE,
            CK_GREEN_6 = CKGREEN | CKSIX,
            CK_GREEN_7 = CKGREEN | CKSEVEN,
            CK_GREEN_8 = CKGREEN | CKEIGHT,
            CK_GREEN_9 = CKGREEN | CKNINE,

            // Yellows
            CK_YELLOW_0 = CKYELLOW | CKZERO,
            CK_YELLOW_1 = CKYELLOW | CKONE,
            CK_YELLOW_2 = CKYELLOW | CKTWO,
            CK_YELLOW_3 = CKYELLOW | CKTHREE,
            CK_YELLOW_4 = CKYELLOW | CKFOUR,
            CK_YELLOW_5 = CKYELLOW | CKFIVE,
            CK_YELLOW_6 = CKYELLOW | CKSIX,
            CK_YELLOW_7 = CKYELLOW | CKSEVEN,
            CK_YELLOW_8 = CKYELLOW | CKEIGHT,
            CK_YELLOW_9 = CKYELLOW | CKNINE,

            // Skips
            CK_RED_S    = CKRED    | CKSKIP,
            CK_BLUE_S   = CKBLUE   | CKSKIP,
            CK_GREEN_S  = CKGREEN  | CKSKIP,
            CK_YELLOW_S = CKYELLOW | CKSKIP,

            // Draws
            CK_RED_D    = CKRED    | CKDRAW2,
            CK_BLUE_D   = CKBLUE   | CKDRAW2,
            CK_GREEN_D  = CKGREEN  | CKDRAW2,
            CK_YELLOW_D = CKYELLOW | CKDRAW2,

            // Reverses
            CK_RED_R    = CKRED    | CKREVERSE,
            CK_BLUE_R   = CKBLUE   | CKREVERSE,
            CK_GREEN_R  = CKGREEN  | CKREVERSE,
            CK_YELLOW_R = CKYELLOW | CKREVERSE,

            // etc
            CK_WILD   = CKWILD,
            CK_WILD_D = CKWILDDRAW4,

            // errors
            CK_NONE = 0x0000,
        };

        enum CardNumber{
            CN_ZERO    = 1,
            CN_ONE     = 2,
            CN_TWO     = 2,
            CN_THREE   = 2,
            CN_FOUR    = 2,
            CN_FIVE    = 2,
            CN_SIX     = 2,
            CN_SEVEN   = 2,
            CN_EIGHT   = 2,
            CN_NINE    = 2,
            CN_SKIP    = 2,
            CN_DRAW    = 2,
            CN_REVERSE = 2,
            CN_WILD    = 4,
            CN_WILD4   = 4,

            CN_NUMBER = (CN_ZERO + CN_ONE + CN_TWO + CN_THREE + CN_FOUR + CN_FIVE + CN_SIX + CN_SEVEN + CN_EIGHT + CN_NINE)*4,
            CN_SYMBOL = (CN_SKIP + CN_DRAW + CN_REVERSE)*4 + CN_WILD + CN_WILD4,
            CN_MAX    = CN_NUMBER + CN_SYMBOL,
        };

        class Card;
        class SetCard;

        typedef unsigned short int cardmemorysize;
        typedef cardmemorysize cms;

        class Card final{
            private:
                cms kind;
            public:
                Card();
                Card(CardKind ck);

                CardKind GetKind() const;
                std::string GetOutput() const;

                friend SetCard;
        };

        class SetCard{
            private:
                Card cards[CN_MAX];
            public:
                virtual void Init();
                cms& operator[](unsigned long long int);
                cms operator[](unsigned long long int) const;
                std::string GetOutput() const;
        };

        class Deck : public SetCard{
            public:
                void Init() override;
        };
    }
}
