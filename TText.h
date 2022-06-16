#pragma once
#include "TDataCom.h"


#include <iostream>
#include <fstream>
#include <stack>


class TText;
class TTextLink;

typedef TText* PTText;
typedef TTextLink* PTTextLink;

class TText : public TDataCom {

protected:
	PTTextLink pFirst;
	PTTextLink pCurrent;
	std::stack< PTTextLink > Path;
	std::stack< PTTextLink > St;
	PTTextLink GetFirstAtom(PTTextLink pl);
	void PrintText(PTTextLink ptl);
	PTTextLink ReadText(std::ifstream& TxtFile);
public:
	TText(PTTextLink pl = nullptr);
	~TText() { pFirst = nullptr; }
	PTText getCopy();

	int GoFirstLink(void);
	int GoDownLink(void);
	int GoNextLink(void);
	int GoPrevLink(void);

	std::string GetLine(void);
	void SetLine(std::string s);

	void InsDownLine(std::string s);
	void InsDownSection(std::string s);
	void InsNextLine(std::string s);
	void InsNextSection(std::string s);
	void DelDownLine(void);
	void DelDownSection(void);
	void DelNextLine(void);
	void DelNextSection(void);

	bool Reset(void);
	bool IsTextEnded(void) const;
	int GoNext(void);

	void Read(char* pFileName);
	void Write(char* pFileName);

	void Print(void);
};