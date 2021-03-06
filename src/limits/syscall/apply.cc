#include <cerrno>
#include <string>
#include <seccomp.h>
#include "ssandbox/limits/syscall.h"
#include "ssandbox/utils/exceptions.h"

void ssandbox::apply_seccomp_limits() {
    auto limiter = ssandbox::seccomp_rules::get_instance();
    auto ctx = limiter->get();
    if (seccomp_load(ctx)) {
        // we need to store errno now because new error may occur at seccomp_release
        int now_errno = errno;

        seccomp_release(ctx);
        throw ssandbox::exceptions::syscall_error(now_errno, "Cannot load seccomp limits", __FUNCTION__);
    }

    seccomp_release(ctx);
}