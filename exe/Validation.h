

// prevent multiple inclusion

#if !defined(__VALIDATION_H__)
#define __VALIDATION_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Validation  
{
public:
	// validation routines
	bool isInteger(char str[]) const;
	bool isRegularFile(char str[]) const;
	bool isDirectory(char str[]) const;
	bool isLikeYes(char str[]) const;

	// constructor / destructor
	Validation();
	virtual ~Validation();
};

#endif // !defined(__VALIDATION_H__)
