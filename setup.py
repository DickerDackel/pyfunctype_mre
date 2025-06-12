from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension('pyfunctype_mre', ['src_c/pyfunctype_mre.c']),
    ]
)
