
EXE = sgemm_tune

include ../make.inc

$(EXE): sgemm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) sgemm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);