from setuptools import Extension, setup


setup(ext_modules=[
    Extension(
        name="template",
        sources=["template.c"],
        extra_compile_args=["-Wall"],
        language="c"
    )
])
