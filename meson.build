project(
  'conan-test',
  'cpp',
  version : '0.0.1',
  default_options : [
    'buildtype=release',
    'warning_level=3',
    'cpp_std=c++14',
    'b_ndebug=if-release'],
  license : 'GPL-3',
  meson_version : '>= 0.52.0')

add_global_arguments([
    '-DPACKAGE_NAME="' + meson.project_name() + '"',
    '-DPACKAGE_VERSION="' + meson.project_version() + '"'],
  language : 'cpp')

# eigen dependency
eigen_dep = dependency('eigen3', required : true)
# header paths
inc = include_directories('include')

subdir('include')
subdir('tests')

