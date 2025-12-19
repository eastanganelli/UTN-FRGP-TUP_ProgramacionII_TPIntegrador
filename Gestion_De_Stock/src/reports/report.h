#ifndef REPORT_H
#define REPORT_H


#include "../controller/fecha.h"
#include "../menu/menu_utils.h"
#include "../controller/validation.h"

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Report {
protected:
	string title;

	unsigned int AskYearOrCurrent();
	void PrintDecoratedTitle(const string& text, char deco = '=');

public:
	explicit Report(const string& _title);
	virtual ~Report();

	const string& GetTitle() const;
	virtual void Run() = 0;
};

#endif // REPORT_H
