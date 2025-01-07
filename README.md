

## Installing with Homebrew
When I am trying to use C++ on my macair M2, the first thing is to install llvm and clang.

```
brew update
brew upgrade
brew info llvm
brew install llvm
echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> ~/.zshrc
export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"
export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"
```

## Building and Linking
The compiler variables use for homebrew clang
```
export CC := clang
export CXX := $(CC)++
```
You should also specify the path manually if you don't want to edit your PATH
variable:
```
export CC := /usr/local/opt/llvm/bin/clang
export CXX := $(CC)++
```
Note that if your tools look for `ld` or `ar`, you will likely end up using the Apple
tools. Make sure you change your compiler settings to `llvm-ar` and `llvm-ld` if you want
to utilize the mainline tools.

You will need the following flags for compiling and linking:
```
LDFLAGS += -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib
CPPFLAGS += -I/usr/local/opt/llvm/include -I/usr/local/opt/llvm/include/c++/v1/
```

You can also check whether brew clang is actually installed before adding these
flags. This will help you support users who install clang by other means.
```
ifeq ($(shell brew info llvm 2>&1 | grep -c "Built from source on"), 1)
#we are using a homebrew clang, need new flags
LDFLAGS += -L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib
CPPFLAGS += -I/usr/local/opt/llvm/include -I/usr/local/opt/llvm/include/c++/v1/
endif
```

If you’re getting errors about missing headers like `assert.h`, make sure to run
`xcode-select --install`. This will populate `/usr/include` correctly.
