from setuptools import Extension, setup


setup(ext_modules=[
    Extension("template", ["template.c"])
])
