from conans import ConanFile, AutoToolsBuildEnvironment, tools


class HelloConan(ConanFile):
    name = "cstat"
    version = "0.1"    
    settings = "os", "compiler", "build_type", "arch"    
    default_options = {"shared": True}
    
    def build(self):
        autotools = AutoToolsBuildEnvironment(self)
        autotools.configure()
        autotools.make()

    def package(self):
        self.copy("*.h", dst="include", src="hello")
        self.copy("*hello.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.dylib", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["hello"]

