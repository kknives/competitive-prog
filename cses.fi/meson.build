# set ft meson
cptn = 'cses.fi'

# One file each
src = ['wierd_algorithm.cpp', 'missing_number.cpp', 'repetitions.cpp', 'increasing_array.cpp', 'permutations.cpp',
'distinct_numbers.cpp', 'apartments.cpp', 'playlist.cpp', 'counting_rooms.cpp', 'labyrinth.cpp']
foreach f : src
  executable(f.replace('.cpp', ''), f, override_options : ['cpp_std=c++17'])
endforeach
