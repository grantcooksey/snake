# Snake

-----

You need to install some libraries
* Adafruit GFX Library - 1.11.1
* Adafruit ST7735 and ST7789 Library - 1.10.0

# Tests

Set up from
* https://github.com/memfault/interrupt/tree/master/example/unit-testing
* https://interrupt.memfault.com/blog/unit-testing-basics
* https://github.com/cpputest/cpputest

Install test tools:
```
brew install cpputest lcov clang-format
```

Use `brew info cpputest` to find where the install location is. Use this value to update `CPPUTEST_HOME` in `snake/tests/MakefileWorkerOverrides.md`.

Build and open a coverage report by running `make lcov && open build/test_coverage/index.html`.

## Notes
This repo is set up to work with VSCode and has multiple non-portable C/C++ configurations for different projects defined in `.vscode/c_cpp_properties.json`.
The path structures there depend on the arduino installation and homebrew. If either of those are upgraded or modified, those paths will probably need to be updated.

Intellisense configuration can be set with `CMD+SHIFT+P -> >C/C++: Select a Configuration...`.