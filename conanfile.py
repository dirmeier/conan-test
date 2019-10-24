from conans import ConanFile, Meson, tools
import os

class ConanTest(ConanFile):
    name = "stats"
    version = "0.1"    
    generators = "pkg_config"
    settings = "os", "compiler", "build_type", "arch"    
        
    def build(self):
        meson = Meson(self)
        meson.configure(build_folder="build")
        meson.build()