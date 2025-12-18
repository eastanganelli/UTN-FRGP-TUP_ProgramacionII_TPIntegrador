#include "report.h"

Report::Report(const std::string& _title) : title(_title) {}

Report::~Report() = default;

const std::string& Report::GetTitle() const { return title; }
