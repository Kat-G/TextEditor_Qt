#pragma once

#define DataOk 0
#define DataErr -1

class TDataCom {
protected:
	int RetCode;
	void SetRetCode(const int retCode) {
		RetCode = retCode;
	};
public:

	TDataCom() {};
	int GetRetCode();

};