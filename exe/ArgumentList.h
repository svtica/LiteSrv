
// prevent multiple inclusion

#if !defined(__ARGUMENT_LIST_H__)
#define __ARGUMENT_LIST_H__

class ArgumentList  
{
public:

	// argument types
	typedef enum ArgumentTypes { AL_SWITCH, AL_GNU_SWITCH, AL_STDIN, AL_STRING, AL_EMPTY };

	// argument transformations
	typedef enum ArgumentTransformations { AL_NONE, AL_TO_UPPER, AL_TO_LOWER };

	// argument validations
	typedef enum ArgumentValidations { AL_ANY, AL_IS_INTEGER, AL_IS_DIRECTORY, AL_IS_FILE };

	// constructor and destructor
	ArgumentList(int argc, char* argv[]);
	virtual ~ArgumentList();
	
	// peek next argument overloads
	void peekNextArgument(
			ArgumentTypes           &argumentType,
			ArgumentValidations      argumentValidation,
			bool                    &isValid,
			char                    *nextArgument           = 0,
			ArgumentTransformations  argumentTransformation = AL_NONE
	);

	void peekNextArgument(
			ArgumentTypes           &argumentType,
			char                    *nextArgument           = 0,
			ArgumentTransformations  argumentTransformation = AL_NONE
	);

	// pop next argument overloads
	void popNextArgument(
			ArgumentTypes           &argumentType,
			ArgumentValidations      argumentValidation,
			bool                    &isValid,
			char                    *nextArgument           = 0,
			ArgumentTransformations  argumentTransformation = AL_NONE
	);
	void popNextArgument(
			ArgumentTypes           &argumentType,
			char                    *nextArgument           = 0,
			ArgumentTransformations  argumentTransformation = AL_NONE
	);

	// get number of arguments
	int getNumberOfArguments() const;

	// get argv[0] (ie name of executable)
	void getArgv0(char *argv0) const;			// as entered on the command line
	bool getExeFullPath(char *fullPath) const;	// full path

private:

	// arguments
	int    _argc;
	char** _argv;

	// where we are in the list
	int argIdx;
	int argCh;

	// service function
	void getNextArgument(
			char                     nextArgument[],
			ArgumentTransformations  argumentTransformation,
			ArgumentValidations      argumentValidation,
			bool                     increment,
			ArgumentTypes           &argumentType,
			bool                    &isValid
	);

};

#endif // !defined(__ARGUMENT_LIST_H__)
