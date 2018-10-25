set expandtab
set tabstop=4
set shiftwidth=4
set autoindent
set smartindent
set number
set ic
set incsearch
setlocal spell spelllang=en_us

au BufNewFile Main.java r .../Main.java
au BufNewFile *.cpp r .../cf.cpp
au BufNewFile gen.sh r .../gen.sh
au BufNewFile c r .../c
au BufNewFile j r .../j
