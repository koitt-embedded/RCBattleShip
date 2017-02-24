.SILENT:

MFS  = $(wildcard */Makefile)
DIRS = $(patsubst %/Makefile,%,$(MFS))

all:
	for dir in $(DIRS); do \
	  echo "=============== " $$dir " =================" ; \
	  $(MAKE) -C $$dir; \
	done

tune:
	for dir in $(DIRS); do \
	  echo "=============== " $$dir " =================" ; \
	  $(MAKE) -C $$dir tune; \
	done; \
	mkdir ofld_tbls; find *_tune -name *ofld*.c -exec cp {} ofld_tbls \;

clean:
	for dir in $(DIRS); do \
	  $(MAKE) -C $$dir clean; \
	done

