
EXE = ctrsm_tune

include ../make.inc

$(EXE): ctrsm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) ctrsm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);