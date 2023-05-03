# Snake

-----

You need to install some libraries
* Adafruit GFX Library - 1.11.1
* Adafruit ST7735 and ST7789 Library - 1.10.0

# Tests

Run the tests: `make test`.

Set up from
* https://github.com/memfault/interrupt/tree/master/example/unit-testing
* https://interrupt.memfault.com/blog/unit-testing-basics
* https://github.com/cpputest/cpputest

Install test tools:
```
brew install cpputest lcov clang-format llvm
# https://stackoverflow.com/questions/53111082/how-to-install-clang-tidy-on-macos
ln -s "$(brew --prefix llvm)/bin/clang-tidy" "/usr/local/bin/clang-tidy"
```

Use `brew info cpputest` to find where the install location is. Use this value to update `CPPUTEST_HOME` in `snake/tests/MakefileWorkerOverrides.md`.

Build and open a coverage report by running `make lcov && open build/test_coverage/index.html`.

## Notes
This repo is set up to work with VSCode and has multiple non-portable C/C++ configurations for different projects defined in `.vscode/c_cpp_properties.json`.
The path structures there depend on the arduino installation and homebrew. If either of those are upgraded or modified, those paths will probably need to be updated.

Intellisense configuration can be set with `CMD+SHIFT+P -> >C/C++: Select a Configuration...`.

## clang-format linter

Run the linter with
```
clang-format -i **/*.h **/*.ino **/*.c **/*.cpp
```

This will format the files in-place and it's set up to be automatically run by vs code on save. The `settings.json` needs the following:
```
"editor.formatOnSave": true,
"editor.defaultFormatter" : "ms-vscode.cpptools",
"C_Cpp.clang_format_style": "file",
"C_Cpp.clang_format_fallbackStyle": "Google"
```

## CppuTest

CppuTest is our unit test suite and gets run with `make test`.

The test suite build is pile of cascading makefiles and a little tough to trace but from the `test` dir, `make debug` can help dump most of the flags set during the build.

The CI suite publishes a test report during the run using a junit style report. This is an extra flag passed to Cpputest and can be generated with `make ci-test`.

## Lcov

We generate a coverage report as part of `make test` that can be viewed at `tests/build/test_coverage/index.html`.

## clang-tidy

This is a pretty awesome linter for programming errors. Configuration is set in `.clang-tidy` and although it's not required, it's helpful to give it a compilation database. Normally cmake
can generate this or tools like `compiledb` can also if directly using make. Fortunately, we don't have to mess with that at all here, `arduino-cli` does it for us! This requires we output
the build locally when we compile so that we can easily find it's output. Otherwise, the build ends us in some private folder that a bit hard to track down. Locally, the build is put in `build`
and a `compile_commands.json` is created there. From there, we can use that database with clang-tidy:
```
clang-tidy -p build snake/**/*.ino snake/**/*.c
```
