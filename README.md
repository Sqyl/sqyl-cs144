Stanford CS 144 Networking Lab
==============================

These labs are open to the public under the (friendly) request that to
preserve their value as a teaching tool, solutions not be posted
publicly by anybody.

Website: https://cs144.stanford.edu

To set up the build system: `cmake -S . -B build`

To compile: `cmake --build build`

To run tests: `cmake --build build --target test`

To run speed benchmarks: `cmake --build build --target speed`

To run clang-tidy (which suggests improvements): `cmake --build build --target tidy`

To format code: `cmake --build build --target format`


===============================

Github ID:Sqyl

CS144 Check 0

10/10 Test passed, with bytestream throughput 7.08 Gbit/s.

Way of achieving stream buffer: std::vector

The way of my dealing with some extreme stream input like "" is not good, where I just return if an input stream is empty. A better version should have more complete approach in dealing with the strings.

If you need some help or the comments of my code, please create an issue at this repo to let me know.

