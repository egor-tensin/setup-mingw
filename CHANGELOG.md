v3
--

* Cygwin is no longer supported (and the related parameters
  `cygwin`/`hardlinks` were removed).
* Removed the `static` parameter used to work around static linking issues on
  older Ubuntu runners.

v2
--

* `cc`/`c++` executables are set up to point to the installed compiler
  executables by default.
* Added the `version` parameter to specify the version to install.
* Extended Cygwin support.

v1
--

* Initial release.
