project(
  'Coding Train',
  'c',
  version : '0.1.0',
  default_options : ['c_std=c11', 'warning_level=3'],
)

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)
winmm_dep = cc.find_library('winmm', required : false)

glfw_dep = dependency('glfw3', required : false)
raylib_dep = dependency('raylib', required : false)
if not raylib_dep.found()
  cmake = import('cmake')
  opt_var = cmake.subproject_options()
  opt_var.add_cmake_defines({'WITH_PIC': true})
  raylib_proj = cmake.subproject('raylib', options : opt_var)
  raylib_dep = raylib_proj.dependency('raylib')
  glfw_dep = raylib_proj.dependency('glfw')
endif
sds_dep = dependency('sds')
sodium_dep = dependency('libsodium')
vec_dep = dependency('vec')

common_deps = [m_dep, winmm_dep, glfw_dep, raylib_dep, sodium_dep, sds_dep, vec_dep]

incdir = include_directories('Headers')
subdir('Sources')
