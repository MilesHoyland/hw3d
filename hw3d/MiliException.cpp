#include "MiliException.h"

MiliException::MiliException(int line, const char* file) noexcept
{
}

const char* MiliException::what() const noexcept
{
	return nullptr;
}

const char* MiliException::GetType() const noexcept
{
	return nullptr;
}

int MiliException::GetLine() const noexcept
{
	return 0;
}

const std::string MiliException::GetFile() const noexcept
{
	return std::string();
}

std::string MiliException::GetOriginString() const noexcept
{
	return std::string();
}
