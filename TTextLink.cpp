#include "TTextLink.h"
#include "TText.h"

TTextLink::TTextLink(const TStr s, PTTextLink pn, PTTextLink pd) : pNext(pn), pDown(pd)
{
    if (s != NULL) strcpy(Str, s);
    else Str[0] = '\0';
}

void TTextLink::IntMemSystem(size_t size) {
    MemHeader.pfirst = (PTTextLink)(new char[sizeof(TTextLink) * size]);
    MemHeader.pFree = MemHeader.pfirst;
    MemHeader.plast = MemHeader.pfirst + (size - 1);
    PTTextLink plink = MemHeader.pfirst;
    for (int i = 0; i < size - 1; plink++, i++) {
        plink->pNext = plink + 1;
    }
    plink->pNext = nullptr;
}

void TTextLink::PrintFreeLink() {
    PTTextLink plink = MemHeader.pFree;
    for (; plink != nullptr; plink = plink->pNext)
        std::cout << plink->Str << std::endl;
}

void* TTextLink::operator new(size_t size) {
    PTTextLink plink = MemHeader.pFree;
    if (MemHeader.pFree != nullptr)
        MemHeader.pFree = plink->pNext;
    return plink;
}

void TTextLink::operator delete(void* pM)
{
    PTTextLink pLink = (PTTextLink)(pM);
    pLink->pNext = MemHeader.pFree;
    pLink->pDown = nullptr;
    MemHeader.pFree = pLink;
}

TTextLink::~TTextLink() {
}

bool TTextLink::IsAtom()
{

    return pDown == nullptr;
}

PTTextLink TTextLink::GetNext()
{
    return pNext;
}

PTTextLink TTextLink::GetDown()
{
    return pDown;
}



void TTextLink::MemCleaner(TText& txt) {

    for (txt.Reset(); !txt.IsTextEnded(); txt.GoNext()) {
        txt.SetLine("&&&" + txt.GetLine());
    }
    txt.SetLine("&&&" + txt.GetLine());



    for (PTTextLink tlink = MemHeader.pFree; tlink != nullptr; tlink = tlink->pNext) {
        strcpy(tlink->Str, "&&&");
    }

    for (PTTextLink tlink = MemHeader.pfirst; tlink != MemHeader.plast + 1; tlink++) {
        if (!strncmp("&&&", tlink->Str, 3)) {
            strcpy(tlink->Str, tlink->Str + 3);
        }
        else {
            delete tlink;
        }
    }
}

PTDataValue TTextLink::GetCopy()
{
    return new TTextLink(Str, pNext, pDown);
}

std::ostream& operator<<(std::ostream& os, const TTextLink& tl)
{
    os << tl.Str << std::endl;
    return os;
}


//TTextLink::TTextLink(const TStr s, PTTextLink pn, PTTextLink pd) : pNext(pn), pDown(pd)
//{
//    if (s != NULL) strcpy(Str, s);
//    else Str[0] = '\0';
//}
//
//void TTextLink::IntMemSystem(int size) {
//    MemHeader.pfirst = (PTTextLink)(new char[sizeof(TTextLink) * size]);
//    MemHeader.pFree = MemHeader.pfirst;
//    MemHeader.plast = MemHeader.pfirst + (size - 1);
//    PTTextLink plink = MemHeader.pfirst;
//    for (int i = 0; i < size - 1; plink++,i++) {
//        plink->pNext = plink + 1;
//    }
//    plink->pNext = 0;
//}
//
//void TTextLink::PrintFreeLink() {
//    PTTextLink plink = MemHeader.pfirst;
//    for (; plink != nullptr; plink = plink->pNext)
//        std::cout << plink->Str << std::endl;
//}
//
//void* TTextLink::operator new(size_t size) {
//    PTTextLink plink = MemHeader.pFree;
//    if (MemHeader.pFree != nullptr)
//        MemHeader.pFree = plink->pNext;
//    return plink;
//}
//
//void TTextLink::operator delete(void* pM)
//{
//    PTTextLink pLink = (PTTextLink)(pM);
//    pLink->pNext = MemHeader.pFree;
//    MemHeader.pFree = pLink;
//}
//
//TTextLink::~TTextLink() {}
//
//bool TTextLink::IsAtom()
//{
//
//    return pDown == nullptr;
//}
//
//PTTextLink TTextLink::GetNext()
//{
//    return pNext;
//}
//
//PTTextLink TTextLink::GetDown()
//{
//    return pDown;
//}
//
//PTDataValue TTextLink::GetCopy()
//{
//    return new TTextLink(Str, pNext, pDown);
//}
//
//std::ostream& operator<<(std::ostream& os, const TTextLink& tl)
//{
//    os << tl.Str << std::endl;
//    return os;
//}