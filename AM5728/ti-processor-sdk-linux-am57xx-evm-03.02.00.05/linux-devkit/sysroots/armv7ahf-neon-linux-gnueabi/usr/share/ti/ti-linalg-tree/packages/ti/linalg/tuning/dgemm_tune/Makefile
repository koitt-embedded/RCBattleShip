
EXE = dgemm_tune

include ../make.inc

$(EXE): dgemm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) dgemm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);