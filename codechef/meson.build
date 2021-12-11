# set ft meson
cptn = 'codechef'

# One file each
src = ['example.cpp', 'DEC21C_ROPASCI.cpp']
foreach f : src
  executable(f.strip('.cpp'), f, override_options : ['cpp_std=c++17']) 
endforeach
