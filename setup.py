#****************************************************************************
#* setup.py for zuspec-arl-dm
#****************************************************************************
import os
from setuptools import Extension, find_namespace_packages

version="0.0.1"

proj_dir = os.path.dirname(os.path.abspath(__file__))

try:
    import sys
    sys.path.insert(0, os.path.join(proj_dir, "python"))
    from zsp_arl_dm.__build_num__ import BUILD_NUM
    version += ".%s" % str(BUILD_NUM)
except ImportError:
    pass

isSrcBuild = False

try:
    from ivpm.setup import setup
    isSrcBuild = os.path.isdir(os.path.join(proj_dir, "src"))
    print("vsc-solvers: running IVPM SrcBuild")
except ImportError as e:
    from setuptools import setup
    print("vsc-solvers: running non-src build")

zuspec_arl_dm_dir = proj_dir

if isSrcBuild:
    incdir = os.path.join(proj_dir, "src", "include")
else:
    incdir = os.path.join(proj_dir, "python/zsp_arl_dm/share/include")

ext = Extension("zsp_arl_dm.core",
            sources=[
                os.path.join(zuspec_arl_dm_dir, 'python', "core.pyx"), 
                os.path.join(zuspec_arl_dm_dir, 'python', 'VisitorProxy.cpp'),
                os.path.join(zuspec_arl_dm_dir, 'python', 'MkModelBuildContextArl.cpp'),
            ],
            language="c++",
            include_dirs=[incdir]
        )
ext.cython_directives={'language_level' : '3'}

setup_args = dict(
  name = "zuspec-arl-dm",
  version=version,
  packages=['zsp_arl_dm'],
  package_dir = {'' : 'python'},
  author = "Matthew Ballance",
  author_email = "matt.ballance@gmail.com",
  description = ("Core ARL data model library"),
  long_description = """
  Provides a library interface for creating and evaluating ARL models at an API level
  """,
  license = "Apache 2.0",
  keywords = ["SystemVerilog", "Verilog", "RTL", "Python"],
  url = "https://github.com/zuspec/zuspec-arl-dm",
  install_requires=[
    'vsc-dm',
    'debug-mgr'
  ],
  entry_points={
    'ivpm.pkginfo': [
        'zuspec-arl-dm = zsp_arl_dm.pkginfo.PkgInfo'
    ]
  },
  setup_requires=[
    'setuptools_scm',
    'vsc-dm',
    'debug-mgr',
    'cython',
  ],
  ext_modules=[ ext ]
)

if isSrcBuild:
    setup_args["ivpm_extdep_pkgs"] = ["vsc-dm", "debug-mgr"]
    setup_args["ivpm_extra_data"] = {
        "zsp_arl_dm": [
            ("src/include", "share"),
            ("build/{libdir}/{libpref}zsp-arl-dm{dllext}", ""),
        ]
    }

setup(**setup_args)

