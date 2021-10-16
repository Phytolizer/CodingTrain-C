project(
  'Coding Train',
  'c',
  version : '0.1.0',
  default_options : ['c_std=c11', 'warning_level=3'],
)

raylib_dep = dependency('raylib')
vec_dep = dependency('vec')
sds_dep = dependency('sds')

common_deps = [raylib_dep, vec_dep, sds_dep]

incdir = include_directories('Headers')
subdir('Sources')
