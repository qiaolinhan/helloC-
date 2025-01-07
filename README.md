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

