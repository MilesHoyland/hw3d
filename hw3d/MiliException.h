#pragma once
#include <exception>
#include <string>

// base exception class inheriting from std exception, to capture the line number of exception and the file occured in
class MiliException : public std::exception
{
public:
	MiliException(int line, const char* file) noexcept;
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	int GetLine() const noexcept;
	const std::string GetFile() const noexcept;
	std::string GetOriginString() const noexcept;
private:
	int line;
	std::string file;
protected:
	mutable std::string whatBuffer;
};

