#ifndef REPORT_H
#define REPORT_H

#include <string>

class Report {
protected:
	std::string title;

public:
	explicit Report(const std::string& _title);
	virtual ~Report();

	const std::string& GetTitle() const;
	virtual void Run() = 0;
};

#endif // REPORT_H
