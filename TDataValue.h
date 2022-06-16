#pragma once
class TDataValue;

typedef TDataValue* PTDataValue;

class TDataValue {
public:
	virtual TDataValue* GetCopy() = 0;
};