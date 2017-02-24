.SILENT:

DIRS = hello_with_make matmul integrating_qmss

all:
	for dir in $(DIRS); do \
          echo "=============== " $$dir " =================" ; \
          $(MAKE) -C $$dir; \
        done

clean:
	for dir in $(DIRS); do \
          $(MAKE) -C $$dir clean; \
        done


