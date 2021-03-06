#include <cerrno>
#include <fmt/core.h>
#include <sys/unistd.h>
#include <sys/mount.h>
#include "ssandbox/containerfs.h"
#include "ssandbox/utils/exceptions.h"

void ssandbox::abstruct_container_fs::mount_all() {
    if (mount("none", "/", nullptr, MS_REC | MS_PRIVATE, nullptr))
        throw ssandbox::exceptions::syscall_error(errno, "Cannot make mount namespace private", __FUNCTION__);

    this->mount_main();
    this->_change_root();

    if (this->_mount_tmp_flag)
        this->_mount_tmp();

    if (this->_mount_proc_flag)
        this->_mount_proc();

    this->mount_extra();
}

void ssandbox::abstruct_container_fs::_change_root() {
    if (chdir(this->get_fs_path("target").c_str()))
        throw ssandbox::exceptions::syscall_error(errno, "Cannot change working point", __FUNCTION__);

    if (chroot("./"))
        throw ssandbox::exceptions::syscall_error(errno, "Cannot change root mount point", __FUNCTION__);
}