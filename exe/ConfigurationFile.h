
// prevent multiple inclusion

#if !defined(__CONFIGURATION_FILE_H__)
#define __CONFIGURATION_FILE_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <fstream>
using namespace std;
// ============================================================================
//
// CONSTANT DEFINITIONS
//
// ============================================================================

const int  CFGFILE_SECTION_SIZE                 = 128;
const int  CFGFILE_MAX_LINE_LENGTH              = 5000;
const char CFGFILE_DEFAULT_COMMENT_CHARACTERS[] = "#;";
const char CFGFILE_SECTION_OPEN                 = '[';
const char CFGFILE_SECTION_CLOSE                = ']';
const char CFGFILE_BLANKS[]                     = "		"; // space or tab

class ConfigurationFile  
{
public:

	// open configuration file
	bool openConfigurationFile(char configPath[]);

	// set requested section
	void setRequestedSection(char requestedSection[]);

	// get next configuration directive
	void getNextConfigurationDirective(char directive[],char value[]);

	// which characters are used for comments
	void setCommentCharacters(char commentCharacters[]);

	// constructor and destructor
	ConfigurationFile();
	virtual ~ConfigurationFile();

private:
	// service functions
	char *readNextRealLine();

	// private variables
	char      _requestedSection[CFGFILE_SECTION_SIZE];
	ifstream *configFile;
	char      configLine[CFGFILE_MAX_LINE_LENGTH];
	char     *_commentCharacters;

};

#endif // !defined(__CONFIGURATION_FILE_H__)
