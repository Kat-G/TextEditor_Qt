#include "TTextLink.h"
#include "TText.h"
//
//PTTextLink TText::ReadText(std::ifstream& TxtFile)
//{
//	PTTextLink pHead, ptl;
//	char StrBuff[TextLineLength];
//	pHead = ptl = new TTextLink();
//	while (TxtFile.eof() == 0) {
//		TxtFile.getline(StrBuff, TextLineLength, '\n');
//		if (StrBuff[0] == '}') {
//			//TextLevel--;
//			break;
//		}
//		else if (StrBuff[0] == '{') {
//			//TextLevel++;
//			ptl->pDown = ReadText(TxtFile);
//		}
//		else {
//			ptl->pNext = new TTextLink(StrBuff, nullptr, nullptr);
//			ptl = ptl->pNext;
//		}
//	}
//	ptl = pHead;
//	if (pHead->pDown == nullptr) {
//		pHead = pHead->pNext;
//		delete ptl;
//	}
//	return pHead;
//}
//
//
//PTTextLink TText::GetFirstAtom(PTTextLink pl) {
//	PTTextLink tmp = pl;
//
//	while (!tmp->IsAtom()) {
//		St.push(tmp);
//		tmp = tmp->GetDown();
//	}
//	return tmp;
//}
//
//void TText::PrintText(PTTextLink ptl) {
//	std::cout << ptl->Str;
//}
//
////PTText TText::getCopy() {
//
////}
//
//std::string TText::GetLine(void) {
//	return pCurrent->Str;
//}
//
//void TText::SetLine(std::string s) {
//
//	if (pCurrent == nullptr) {
//		SetRetCode(TextError);
//	}
//	else {
//		strncpy(pCurrent->Str, s.c_str(), TextLineLength);
//		pCurrent->Str[TextLineLength - 1] = '\0';
//		SetRetCode(TextOk);
//	}
//}
//
//TText::TText(PTTextLink pl) {
//	if (pl == nullptr) {
//		pl = new TTextLink();
//	}
//	pFirst = pl;
//	pCurrent = pl;
//
//}
//
//int TText::GoFirstLink(void)
//{
//	while (!Path.empty()) {
//		Path.pop();
//	}
//
//	pCurrent = pFirst;
//
//	if (pCurrent == nullptr) SetRetCode(TextError);
//	else SetRetCode(TextOk);
//
//	return RetCode;
//}
//
//int TText::GoNextLink(void)
//{
//	SetRetCode(TextError);
//	if (pCurrent != nullptr)
//		if (pCurrent->pNext != nullptr) {
//			Path.push(pCurrent);
//			pCurrent = pCurrent->pNext;
//			SetRetCode(TextOk);
//		}
//	return RetCode;
//}
//
//int TText::GoDownLink(void) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr)
//		if (pCurrent->pDown != nullptr) {
//			Path.push(pCurrent);
//			pCurrent = pCurrent->pDown;
//			SetRetCode(TextOk);
//		}
//	return RetCode;
//}
//
//int TText::GoPrevLink(void) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr)
//		if (!Path.empty()) {
//			pCurrent = Path.top();
//			Path.pop();
//			SetRetCode(TextOk);
//		}
//	return RetCode;
//}
//
//void TText::InsDownLine(std::string s) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pd = pCurrent->pDown;
//		pCurrent->pDown = new TTextLink(s.c_str(), pd, nullptr);
//
//		SetRetCode(TextOk);
//	}
//}
//
//void TText::InsDownSection(std::string s) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pd = pCurrent->pDown;
//		pCurrent->pDown = new TTextLink(s.c_str(), nullptr, pd);
//
//		SetRetCode(TextOk);
//	}
//}
//
//void TText::InsNextLine(std::string s) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pn = pCurrent->pNext;
//		pCurrent->pNext = new TTextLink(s.c_str(), pn, nullptr);
//
//		SetRetCode(TextOk);
//	}
//}
//
//void TText::InsNextSection(std::string s) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pn = pCurrent->pNext;
//		pCurrent->pNext = new TTextLink(s.c_str(), nullptr, pn);
//
//		SetRetCode(TextOk);
//	}
//}
//
//void TText::DelDownLine(void) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pd = pCurrent->pDown;
//		if (pd != nullptr) {
//			if (pd->IsAtom()) {
//				PTTextLink pdn = pd->pNext;
//				pCurrent->pDown = pdn;
//			}
//			SetRetCode(TextOk);
//		}
//		else {
//			SetRetCode(TextNoDown);
//		}
//	}
//}
//
//void TText::DelNextLine(void) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pn = pCurrent->pNext;
//		if (pn != nullptr) {
//			if (pn->IsAtom()) {
//				PTTextLink pnn = pn->pNext;
//				pCurrent->pNext = pnn;
//			}
//			SetRetCode(TextOk);
//		}
//		else {
//			SetRetCode(TextNoDown);
//		}
//	}
//}
//
//void TText::DelDownSection(void) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pd = pCurrent->pDown;
//		if (pd != nullptr) {
//			PTTextLink pdn = pd->pNext;
//			pCurrent->pDown = pdn;
//
//			SetRetCode(TextOk);
//		}
//		else {
//			SetRetCode(TextNoDown);
//		}
//	}
//}
//
//void TText::DelNextSection(void) {
//	SetRetCode(TextError);
//	if (pCurrent != nullptr) {
//
//		PTTextLink pn = pCurrent->pNext;
//		if (pn != nullptr) {
//			PTTextLink pnn = pn->pNext;
//			pCurrent->pNext = pnn;
//
//			SetRetCode(TextOk);
//		}
//		else {
//			SetRetCode(TextNoDown);
//		}
//	}
//}
//
//bool TText::Reset(void)
//{
//	while (!St.empty()) St.pop();
//
//	pCurrent = pFirst;
//
//	if (pCurrent != nullptr) {
//		//St.push(pCurrent);
//		if (pCurrent->pNext != nullptr) {
//			St.push(pCurrent->pNext);
//		}
//		if (pCurrent->pDown != nullptr) {
//			St.push(pCurrent->pDown);
//		}
//
//	}
//	return IsTextEnded();
//}
//
//bool TText::IsTextEnded(void) const
//{
//	return !St.size();
//}
//
//int TText::GoNext(void)
//{
//	if (!IsTextEnded()) {
//		pCurrent = St.top();
//		St.pop();
//		//if (pCurrent != pFirst) {
//		if (pCurrent->pNext != nullptr) {
//			St.push(pCurrent->pNext);
//		}
//		if (pCurrent->pDown != nullptr) {
//			St.push(pCurrent->pDown);
//		}
//		//}
//	}
//	return IsTextEnded();
//}
//
///*void TText::Read(char* pFileName) {
//
//}
//void TText::Write(char* pFileName) {
//
//}
//void TText::Print(void) {
//
//}*/

PTTextLink TText::GetFirstAtom(PTTextLink pl) {
	PTTextLink tmp = pl;

	while (!tmp->IsAtom()) {
		St.push(tmp);
		tmp = tmp->GetDown();
	}
	return tmp;
}

void TText::PrintText(PTTextLink ptl) {
	std::cout << ptl->Str;
}

//PTText TText::getCopy() {

//}

PTText TText::getCopy() {
	PTTextLink pl1, pl2, pl = pFirst, cpl = nullptr;
	if (pFirst != nullptr) {
		while (!St.empty())
			St.pop();
		while (true) {
			if (pl != nullptr) {
				pl = GetFirstAtom(pl);
				St.push(pl);
				pl = pl->GetDown();
			}
			else if (St.empty())
				break;
			else {
				pl1 = St.top();
				St.pop();
				if (strstr(pl1->Str, "Copy") == NULL) {
					pl2 = new TTextLink("Copy", pl1, cpl);
					St.push(pl2);
					pl = pl1->GetNext();
					cpl = nullptr;
				}
				else {
					pl2 = pl1->GetNext();
					strcpy(pl1->Str, pl2->Str);
					pl1->pNext = cpl;
					cpl = pl1;
				}
			}
		}
	}
	return new TText(cpl);
}

std::string TText::GetLine(void) {
	return pCurrent->Str;
}

void TText::SetLine(std::string s) {

	if (pCurrent == nullptr) {
		SetRetCode(TextError);
	}
	else {
		strncpy(pCurrent->Str, s.c_str(), TextLineLength);
		pCurrent->Str[TextLineLength - 1] = '\0';
		SetRetCode(TextOk);
	}
}

TText::TText(PTTextLink pl) {
	if (pl == nullptr) {
		pl = new TTextLink();
	}
	pFirst = pl;
	pCurrent = pl;

}

int TText::GoFirstLink(void)
{
	while (!Path.empty()) {
		Path.pop();
	}

	pCurrent = pFirst;

	if (pCurrent == nullptr) SetRetCode(TextError);
	else SetRetCode(TextOk);

	return RetCode;
}

int TText::GoNextLink(void)
{
	SetRetCode(TextError);
	if (pCurrent != nullptr)
		if (pCurrent->pNext != nullptr) {
			Path.push(pCurrent);
			pCurrent = pCurrent->pNext;
			SetRetCode(TextOk);
		}
	return RetCode;
}

int TText::GoDownLink(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr)
		if (pCurrent->pDown != nullptr) {
			Path.push(pCurrent);
			pCurrent = pCurrent->pDown;
			SetRetCode(TextOk);
		}
	return RetCode;
}

int TText::GoPrevLink(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr)
		if (!Path.empty()) {
			pCurrent = Path.top();
			Path.pop();
			SetRetCode(TextOk);
		}
	return RetCode;
}

void TText::InsDownLine(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		pCurrent->pDown = new TTextLink(s.c_str(), pd, nullptr);
		if (pCurrent->pDown == nullptr) {
			TTextLink::MemCleaner(*this);
			pCurrent->pDown = new TTextLink(s.c_str(), pd, nullptr);
		}
		if (pCurrent->pDown == nullptr) SetRetCode(TextNoMem);
		else SetRetCode(TextOk);
	}
}

void TText::InsDownSection(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		pCurrent->pDown = new TTextLink(s.c_str(), nullptr, pd);
		if (pCurrent->pDown == nullptr) {
			TTextLink::MemCleaner(*this);
			pCurrent->pDown = new TTextLink(s.c_str(), nullptr, pd);
		}
		if (pCurrent->pDown == nullptr) SetRetCode(TextNoMem);
		else SetRetCode(TextOk);
	}
}

void TText::InsNextLine(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		pCurrent->pNext = new TTextLink(s.c_str(), pn, nullptr);
		if (pCurrent->pNext == nullptr) {
			TTextLink::MemCleaner(*this);
			pCurrent->pNext = new TTextLink(s.c_str(), pn, nullptr);
		}
		if (pCurrent->pNext == nullptr) SetRetCode(TextNoMem);
		else SetRetCode(TextOk);
	}
}

void TText::InsNextSection(std::string s) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		pCurrent->pNext = new TTextLink(s.c_str(), nullptr, pn);
		if (pCurrent->pNext == nullptr) {
			TTextLink::MemCleaner(*this);
			pCurrent->pNext = new TTextLink(s.c_str(), nullptr, pn);
		}
		if (pCurrent->pNext == nullptr) SetRetCode(TextNoMem);
		else SetRetCode(TextOk);
	}
}

void TText::DelDownLine(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		if (pd != nullptr) {
			if (pd->IsAtom()) {
				PTTextLink pdn = pd->pNext;
				pCurrent->pDown = pdn;
			}
			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

void TText::DelNextLine(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		if (pn != nullptr) {
			if (pn->IsAtom()) {
				PTTextLink pnn = pn->pNext;
				pCurrent->pNext = pnn;
			}
			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

void TText::DelDownSection(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pd = pCurrent->pDown;
		if (pd != nullptr) {
			PTTextLink pdn = pd->pNext;
			pCurrent->pDown = pdn;

			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

void TText::DelNextSection(void) {
	SetRetCode(TextError);
	if (pCurrent != nullptr) {

		PTTextLink pn = pCurrent->pNext;
		if (pn != nullptr) {
			PTTextLink pnn = pn->pNext;
			pCurrent->pNext = pnn;

			SetRetCode(TextOk);
		}
		else {
			SetRetCode(TextNoDown);
		}
	}
}

bool TText::Reset(void)
{
	while (!St.empty()) St.pop();

	pCurrent = pFirst;

	if (pCurrent != nullptr) {
		//St.push(pCurrent);
		if (pCurrent->pNext != nullptr) {
			St.push(pCurrent->pNext);
		}
		if (pCurrent->pDown != nullptr) {
			St.push(pCurrent->pDown);
		}

	}
	return IsTextEnded();
}

bool TText::IsTextEnded(void) const
{
	return !St.size();
}

int TText::GoNext(void)
{
	if (!IsTextEnded()) {
		pCurrent = St.top();
		St.pop();
		//if (pCurrent != pFirst) {
		if (pCurrent->pNext != nullptr) {
			St.push(pCurrent->pNext);
		}
		if (pCurrent->pDown != nullptr) {
			St.push(pCurrent->pDown);
		}
		//}
	}
	return IsTextEnded();
}

void TText::Read(char* pFileName) {
	PTTextLink first;

	TTextLink::MemCleaner(*this);
	first = new TTextLink();
	if (first == nullptr) {
		SetRetCode(TextNoMem);
		return;
	}

	PTText tmpText = new TText(first);
	size_t lastLevel = 0, Level, NextCounter = 0;

	TStr line;
	std::ifstream file;

	file.open(pFileName);

	file.getline(line, TextLineLength);
	Level = 0;
	while (line[0] == '\t') {
		std::strcpy(line, line + 1);
		Level++;
	}
	lastLevel = Level;

	tmpText->SetLine(line);

	while (!file.eof()) {
		file.getline(line, TextLineLength);
		Level = 0;
		while (line[0] == '\t') {
			std::strcpy(line, line + 1);
			Level++;
		}

		if (Level > lastLevel) {
			tmpText->InsDownLine(line);

			if (RetCode != TextOk) {
				SetRetCode(TextNoMem);
				TTextLink::MemCleaner(*this);
				return;
			}

			tmpText->GoDownLink();
		}
		else if (Level == lastLevel) {
			tmpText->InsNextLine(line);

			if (RetCode != TextOk) {
				SetRetCode(TextNoMem);
				TTextLink::MemCleaner(*this);
				return;
			}
			NextCounter++;
			tmpText->GoNextLink();
		}
		else {
			for (size_t i = 0; i < lastLevel - Level + NextCounter; i++) {
				tmpText->GoPrevLink();
			}

			tmpText->InsNextLine(line);

			if (RetCode != TextOk) {
				SetRetCode(TextNoMem);
				TTextLink::MemCleaner(*this);
				return;
			}
			NextCounter = 1;
			tmpText->GoNextLink();
		}

		lastLevel = Level;
	}

	pFirst = tmpText->pFirst;
	pCurrent = pFirst;
	TTextLink::MemCleaner(*this);
}

void TText::Write(char* pFileName) {
	std::ofstream file;

	file.open(pFileName, std::ios_base::trunc);
	PTTextLink cur = pCurrent;

	Reset();

	size_t level = 0;
	std::stack<size_t> nexts;
	size_t steckSize = St.size();
	bool down;

	while (!IsTextEnded()) {

		/*for (int i = 0; i < level; i++) {
			file << '\t';
		}*/
		file << pCurrent->Str;
		down = (pCurrent->pDown != nullptr);
		if (pCurrent->pNext != nullptr) nexts.push(level);
		GoNext();

		if (down) {

			level++;
			steckSize = St.size();
		}
		else {
			level = nexts.top();
			nexts.pop();
		}
		file << std::endl;
	}

	/*for (int i = 0; i < level; i++) {
		file << '\t';
	}*/

	file << pCurrent->Str;
	pCurrent = cur;
}

void TText::Print(void) {
	PTTextLink cur = pCurrent;

	Reset();

	size_t level = 0;
	std::stack<size_t> nexts;
	size_t steckSize = St.size();
	bool down;

	while (!IsTextEnded()) {

		for (int i = 0; i < level; i++) {
			std::cout << '\t';
		}
		PrintText(pCurrent);
		down = (pCurrent->pDown != nullptr);
		if (pCurrent->pNext != nullptr) nexts.push(level);
		GoNext();

		if (down) {

			level++;
			steckSize = St.size();
		}
		else {
			level = nexts.top();
			nexts.pop();
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < level; i++) {
		std::cout << '\t';
	}

	PrintText(pCurrent);
	pCurrent = cur;
}