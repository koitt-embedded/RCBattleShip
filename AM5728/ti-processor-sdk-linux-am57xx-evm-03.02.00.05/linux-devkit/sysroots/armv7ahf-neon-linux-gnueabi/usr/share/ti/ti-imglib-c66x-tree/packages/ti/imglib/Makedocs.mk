# ==============================================================================
# File            : Makedocs.mk
# Description     : 
#
#   GNU makefile to generate release notes using Doxygen
#
# ==============================================================================

# The target for generating release Notes using doxygen is releasenotes

RELEASE_DOC=./docs/doxygen/release.chm

releasenotes : $(RELEASE_DOC)

$(RELEASE_DOC): ./docs/doxygen/release.h
	-@echo generating Release Notes ...
	if test ! -d ./docs/doxygen/html; then mkdir ./docs/doxygen/html; fi
	cp $(TI_DOXYGEN_TEMPLATES)/*.* ./docs/doxygen/html
	doxygen ../mas/swtools/docs/doxygen/releaseDoxyfile
	@xs -f ../mas/swtools/release.js

IMGLIB_DOC      =./docs/doxygen/IMGLIB_Function_Reference.chm
IMGLIB_MANIFEST =./docs/manifest/Software_Manifest.html

release: $(IMGLIB_MANIFEST) $(IMGLIB_DOC)

gendocs $(IMGLIB_DOC): ./docs/doxygen/doxygen.h
	-@echo generating IMGLIB documentation ...
	if test ! -d ./docs/doxygen/html; then mkdir ./docs/doxygen/html; fi
	cp $(TI_DOXYGEN_TEMPLATES)/*.* ./docs/doxygen/html
	doxygen ./docs/doxygen/Doxyfile

genmanifest $(IMGLIB_MANIFEST): ./docs/manifest/manifest.xml
	-@echo generating IMGLIB Software Manifest ...
	@php ../mas/swtools/mangen.php $(IMGLIB_MANIFEST) $?

# End of Makedocs.mk
