from setuptools import Extension, setup


setup(ext_modules=[
    Extension(
        name="template",
        sources=["template.c"],
        include_dirs=[
            "D:/python/Lib/site-packages/numpy/core/include/"
        ],
        extra_compile_args=["-Wall"],
        language="c"
    )
])
