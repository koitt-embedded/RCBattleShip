.PHONY: clean all install lib examples

all: lib examples


lib:
	cd src; make TARGET=$(TARGET) LIBOS=$(LIBOS);

examples:
	cd examples; make TARGET=$(TARGET) LIBOS=$(LIBOS);

install:
	tar -czf libArch.tar.gz --exclude='*.git' --exclude="*.obj"  --files-from=./build/tar_files_list.txt; \
	mkdir -p $(DESTDIR); tar -xf libArch.tar.gz -C $(DESTDIR);

clean:
	cd src; make clean; 

docs: docs/doxygen/doxycfg.txt
	doxygen docs/doxygen/doxycfg.txt