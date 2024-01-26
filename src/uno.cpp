#include <uno.hpp>

amo::uno::Card::Card()
{
    this->kind = CK_NONE;
}

amo::uno::Card::Card(CardKind ck)
{
    this->kind = ck;
}

amo::uno::CardKind amo::uno::Card::GetKind() const
{
    return (CardKind)this->kind;
}

std::string amo::uno::Card::GetOutput() const
{
    std::string rstr = "<";
    switch(this->kind & CKCOLOR){
        case CKRED:
            rstr += "R";
            break;
        case CKBLUE:
            rstr += "B";
            break;
        case CKGREEN:
            rstr += "G";
            break;
        case CKYELLOW:
            rstr += "Y";
            break;
    }

    switch(this->kind & CKNUMBER){
        case CKZERO:
            rstr += "0";
            break;
        case CKONE:
            rstr += "1";
            break;
        case CKTWO:
            rstr += "2";
            break;
        case CKTHREE:
            rstr += "3";
            break;
        case CKFOUR:
            rstr += "4";
            break;
        case CKFIVE:
            rstr += "5";
            break;
        case CKSIX:
            rstr += "6";
            break;
        case CKSEVEN:
            rstr += "7";
            break;
        case CKEIGHT:
            rstr += "8";
            break;
        case CKNINE:
            rstr += "9";
            break;
    }

    switch(this->kind & CKSYMBOL){
        case CKSKIP:
            rstr += "S";
            break;
        case CKDRAW2:
            rstr += "D";
            break;
        case CKREVERSE:
            rstr += "R";
            break;
        case CKWILD:
            rstr += "WI";
            break;
        case CKWILDDRAW4:
            rstr += "W4";
            break;
    }
    rstr += ">";

    return rstr;
    return "uno";
}

void amo::uno::SetCard::Init()
{
    for(unsigned long long int i = 0 ; i < CN_MAX ; i++){
        this->cards[i].kind = CK_NONE;
    }
}

amo::uno::cms& amo::uno::SetCard::operator[](unsigned long long int e)
{
    return this->cards[e%CN_MAX].kind;
}

amo::uno::cms amo::uno::SetCard::operator[](unsigned long long int e) const
{
    return this->cards[e%CN_MAX].kind;
}

std::string amo::uno::SetCard::GetOutput() const
{
    std::string rstr;

    for(unsigned long long int i = 0 ; i < CN_MAX ; i++){
        rstr += this->cards[i].GetOutput();
    }

    return rstr;
}

void amo::uno::Deck::Init()
{
    unsigned long long int e = 0;
    CardKind color[] = {CKRED, CKBLUE, CKGREEN, CKYELLOW};

    /* coloring */
    CardKind   clkind[]   = {CKZERO,  CKONE,  CKTWO,  CKTHREE,  CKFOUR,  CKFIVE,  CKSIX,  CKSEVEN,  CKEIGHT,  CKNINE,  CKSKIP,  CKDRAW2, CKREVERSE};
    CardNumber clnumber[] = {CN_ZERO, CN_ONE, CN_TWO, CN_THREE, CN_FOUR, CN_FIVE, CN_SIX, CN_SEVEN, CN_EIGHT, CN_NINE, CN_SKIP, CN_DRAW, CN_REVERSE};

    /* non coloring */
    CardKind   nckind[]   = {CKWILD,  CKWILDDRAW4};
    CardNumber ncnumber[] = {CN_WILD, CN_WILD4};

    for(unsigned long long int c = 0 ; c < sizeof(color)/sizeof(CardKind) ; c++){
        for(unsigned long long int cl = 0 ; cl < sizeof(clkind)/sizeof(CardKind) ; cl++){
            for(unsigned long long int n = 0 ; n < clnumber[cl] ; n++){
                this->operator[](e) = color[c] | clkind[cl];
                e++;
            }
        }
    }

    for(unsigned long long int nc = 0 ; nc < sizeof(nckind)/sizeof(CardKind) ; nc++){
        for(unsigned long long int n = 0 ; n < ncnumber[nc] ; n++){
            this->operator[](e) = nckind[nc];
            e++;
        }
    }
}
