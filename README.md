# This repo was archived for NO LONGER MAINTAINANCE!
# Please use the rust version instead: https://github.com/segment-oj/ssandbox-rs

# segment-sandbox

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/0798b606d4be40c59daf03cb69433b75)](https://app.codacy.com/gh/segment-oj/segment-sandbox?utm_source=github.com&utm_medium=referral&utm_content=segment-oj/segment-sandbox&utm_campaign=Badge_Grade_Settings)
![CodeQL Analyze](https://github.com/segment-oj/segment-sandbox/workflows/CodeQL%20Analyze/badge.svg)

The sandbox for segment-judger using linux namespace, cgroup and seccomp

基于Linux namespace, cgroup 和 seccomp 的沙箱系统，segmentoj-judger并不将使用它。

查看wiki获得更多信息。

# Install Requirements
You need g++-9 or later (clang++10.0 or later), witch has full C++17 support (Ubuntu 20.04 LTS or Alpine Linux is a good choice).

C++ lib **{fmt}** is required.

Also, `libseccomp` required. 

You need `make` and `cmake` to compile.
