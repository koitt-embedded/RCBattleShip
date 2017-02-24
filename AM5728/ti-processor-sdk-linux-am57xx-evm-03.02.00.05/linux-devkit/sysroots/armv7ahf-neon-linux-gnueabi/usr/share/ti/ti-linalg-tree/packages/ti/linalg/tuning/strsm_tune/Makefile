
EXE = strsm_tune

include ../make.inc

$(EXE): strsm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) strsm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);