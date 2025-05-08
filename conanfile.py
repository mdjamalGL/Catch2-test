from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeDeps, CMakeToolchain


class Catch2TestConan(ConanFile):
    name = "catch2_test"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    exports_sources = "CMakeLists.txt", "prog.h", "prog.cpp", "test.cpp"

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("catch2/3.5.2")
        self.requires("nlohmann_json/3.12.0")
        self.requires("fakeit/2.4.1", options={"fakeit/*:integration": "catch"})
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def test(self):
        self.run(os.path.join(self.cpp.build.bindir, "test_main"), env="conanrun")
