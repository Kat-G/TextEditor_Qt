#pragma once
#include <iostream>
#include "TDataValue.h"


#define TextOk 0
#define TextNoDown 101
#define TextNoNext 102
#define TextNoPrev 103

#define TextNoMem -101
#define TextError -102
#define TextLineLength 100

#define MemSize 20



class TText;
class TTextLink;
class TTextMem;

typedef TTextMem* PTTextMem;
typedef char TStr[TextLineLength];
typedef TTextLink* PTTextLink;

class TTextMem {
	PTTextLink pfirst;
	PTTextLink plast;
	PTTextLink pFree;
	friend class TTextLink;
};


class TTextLink : public TDataValue {
protected:
	PTTextLink pNext;
	PTTextLink pDown;
	TStr Str;
	inline static TTextMem MemHeader;
public:


	TTextLink(const TStr s = NULL, PTTextLink pn = nullptr, PTTextLink pd = nullptr);

	static void IntMemSystem(size_t size = MemSize);

	void PrintFreeLink();

	void* operator new(size_t size);

	void operator delete(void* pM);

	void static  MemCleaner(TText& txt);

	~TTextLink();

	bool IsAtom();

	PTTextLink GetNext();

	PTTextLink GetDown();

	PTDataValue GetCopy();


protected:

	friend std::ostream& operator << (std::ostream& os, const TTextLink& tl);

	friend class TText;

};
//
//class TText;
//class TTextLink;
//class TTextMem;
//
//typedef TTextMem* PTTextMem;
//typedef char TStr[TextLineLength];
//typedef TTextLink* PTTextLink;
//
//class TTextMem {
//	PTTextLink pfirst;
//	PTTextLink plast;
//	PTTextLink pFree;
//	friend class TTextLink;
//};
//
//
//class TTextLink : public TDataValue {
//protected:
//	PTTextLink pNext;
//	PTTextLink pDown;
//	TStr Str;
//	inline static TTextMem MemHeader;
//public:
//
//	TTextLink(const TStr s = NULL, PTTextLink pn = NULL, PTTextLink pd = NULL);
//
//	static void IntMemSystem(int size = MemSize);
//
//	void PrintFreeLink();
//
//	void* operator new(size_t size);
//
//	void operator delete(void* pM);
//
//	static void MemCleaner(const TText& txt);
//
//	~TTextLink();
//
//	bool IsAtom();
//
//	PTTextLink GetNext();
//
//	PTTextLink GetDown();
//
//	PTDataValue GetCopy();
//
//protected:
//
//	friend std::ostream& operator << (std::ostream& os, const TTextLink& tl);
//
//	friend class TText;
//
//};