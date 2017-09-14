from distutils.core import setup, Extension

module1 = Extension('my_math',
                    sources = ['my_math.cc'])

setup(name="Packagename", version="1.0", description="demo package", ext_modules=[module1])
