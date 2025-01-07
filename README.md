

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
