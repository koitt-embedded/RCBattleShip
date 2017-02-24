
EXE = strmm_tune

include ../make.inc

$(EXE): strmm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) strmm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);