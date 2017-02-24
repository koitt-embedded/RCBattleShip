
EXE = cgemm_tune

include ../make.inc

$(EXE): cgemm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) cgemm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);