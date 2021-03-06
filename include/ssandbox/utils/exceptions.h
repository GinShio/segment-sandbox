// -*- C++ -*- Part of the Segment Sandbox Project

#ifndef SSANDBOX_UTILS_EXCEPTIONS_H
#define SSANDBOX_UTILS_EXCEPTIONS_H

#include <exception>
#include <stdexcept>
#include <string>

namespace ssandbox {

namespace exceptions {

std::string error_msg(std::string message, std::string function);

class syscall_error : public std::exception {
public:
    syscall_error(int errorno, const std::string& message, const std::string& function);
    ~syscall_error();

    const char* what() const throw();

private:
    std::string _message;
};

} // namespace exceptions

} // namespace ssandbox

#endif // SSANDBOX_UTILS_EXCEPTIONS_H