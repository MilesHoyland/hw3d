#include "MiliException.h"
#include <sstream>
MiliException::MiliException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

//creates the what display string storing in the what buffer
const char* MiliException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* MiliException::GetType() const noexcept
{
	return "Mili Exception";
}

int MiliException::GetLine() const noexcept
{
	return line;
}

const std::string MiliException::GetFile() const noexcept
{
	return file;
}

std::string MiliException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File]" << file << std::endl
		<< "[Line]" << line;
	return oss.str();
}
