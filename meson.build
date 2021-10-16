project(
  'Coding Train',
  'c',
  version : '0.1.0',
  default_options : ['c_std=c11', 'warning_level=3'],
)

raylib_dep = dependency('raylib')
sds_dep = dependency('sds')
sodium_dep = dependency('libsodium')
vec_dep = dependency('vec')

common_deps = [raylib_dep, sodium_dep, sds_dep, vec_dep]

incdir = include_directories('Headers')
subdir('Sources')
